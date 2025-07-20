/*
 * LocalSocketIpcClient.cpp
 *
 *  Created on: 19.10.2014
 *      Author: Selur
 */

#include "LocalSocketIpcClient.h"
#include <QDataStream>

LocalSocketIpcClient::LocalSocketIpcClient(const QString &remoteServername, QObject *parent)
    : QObject(parent), m_blockSize(0)
{

  m_socket = new QLocalSocket(this);
  m_serverName = remoteServername;

  QObject::connect(m_socket, SIGNAL(connected()), this, SLOT(socket_connected()));
  QObject::connect(m_socket, SIGNAL(disconnected()), this, SLOT(socket_disconnected()));

  QObject::connect(m_socket, SIGNAL(readyRead()), this, SLOT(socket_readReady()));
#if (QT_VERSION < QT_VERSION_CHECK(6, 0, 0))
  QObject::connect(m_socket, SIGNAL(error(QLocalSocket::LocalSocketError)), this, SLOT(socket_error(QLocalSocket::LocalSocketError)));
#else
  QObject::connect(m_socket, SIGNAL(errorOccurred(QLocalSocket::LocalSocketError)), this, SLOT(socket_error(QLocalSocket::LocalSocketError)));
#endif
}

LocalSocketIpcClient::~LocalSocketIpcClient()
{
}

void LocalSocketIpcClient::send_MessageToServer(const QString& message)
{
  m_message = message;
  if (m_socket->state() != QLocalSocket::ConnectedState) {
    m_socket->connectToServer(m_serverName);
    m_socket->waitForConnected();
  }
  this->socket_connected();
}

void LocalSocketIpcClient::socket_connected()
{
  if (m_message == QString()) {
    return;
  }
  QByteArray block;
  QDataStream out(&block, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_5_5);
  out << m_message.toUtf8();
  out.device()->seek(0);
  m_message = QString();
  m_socket->write(block);
  m_socket->flush();
}

void LocalSocketIpcClient::socket_disconnected()
{
  emit signalWriteLogMessage(0, "[VSE Client]: socket disconnected,..");
}

void LocalSocketIpcClient::socket_readReady()
{
  emit signalWriteLogMessage(0, "[VSE Client]: socket read ready,..");
}

void LocalSocketIpcClient::socket_error(QLocalSocket::LocalSocketError error)
{
  QString message;
  if (error == QLocalSocket::ConnectionRefusedError) {
    message = "connection was refused by the peer (or timed out).";
  } else if (error == QLocalSocket::PeerClosedError) {
    message = "remote socket closed the connection. Note that the client socket (i.e., this socket) will be closed after the remote close notification has been sent.";
  } else if (error == QLocalSocket::ServerNotFoundError) {
    message = "local socket name was not found.";
  } else if (error == QLocalSocket::SocketAccessError) {
    message = "socket operation failed because the application lacked the required privileges.";
  } else if (error == QLocalSocket::SocketResourceError) {
    message = "local system ran out of resources (e.g., too many sockets).";
  } else if (error == QLocalSocket::SocketTimeoutError) {
    message = "socket operation timed out.";
  } else if (error == QLocalSocket::DatagramTooLargeError) {
    message = "datagram was larger than the operating system's limit (which can be as low as 8192 bytes).";
  } else if (error == QLocalSocket::ConnectionError) {
    message = "An error occurred with the connection.";
  } else if (error == QLocalSocket::UnsupportedSocketOperationError) {
    message = "requested socket operation is not supported by the local operating system.";
  } else if (error == QLocalSocket::OperationError) {
    message = "An operation was attempted while the socket was in a state that did not permit it.";
  } else if (error == QLocalSocket::UnknownSocketError) {
    message = "An unidentified error occurred.";
  }
  emit signalWriteLogMessage(0, "[VSE Client]: socket error - " + message);
}
