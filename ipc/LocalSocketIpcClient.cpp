/*
 * LocalSocketIpcClient.cpp
 *
 *  Created on: 19.10.2014
 *      Author: Selur
 */

#include "LocalSocketIpcClient.h"
#include <QDataStream>

LocalSocketIpcClient::LocalSocketIpcClient(QString remoteServername, QObject *parent)
    : QObject(parent), m_blockSize(0)
{

  m_socket = new QLocalSocket(this);
  m_serverName = remoteServername;

  QObject::connect(m_socket, SIGNAL(connected()), this, SLOT(socket_connected()));
  QObject::connect(m_socket, SIGNAL(disconnected()), this, SLOT(socket_disconnected()));

  QObject::connect(m_socket, SIGNAL(readyRead()), this, SLOT(socket_readReady()));
  QObject::connect(m_socket, SIGNAL(error(QLocalSocket::LocalSocketError)), this, SLOT(socket_error(QLocalSocket::LocalSocketError)));
}

LocalSocketIpcClient::~LocalSocketIpcClient()
{
}

void LocalSocketIpcClient::send_MessageToServer(QString message)
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
  out.setVersion(QDataStream::Qt_4_6); //TODO: adjust once QT 4.6 support is dropped
  out << m_message;
  out.device()->seek(0);
  m_message = QString();
  m_socket->write(block);
  m_socket->flush();
}

void LocalSocketIpcClient::socket_disconnected()
{
#if QT_DEBUG
  emit signalWriteLogMessage(0, "[VSE Client]: socket disconnected,..");
#endif
}

void LocalSocketIpcClient::socket_readReady()
{
#if QT_DEBUG
  emit signalWriteLogMessage(0, "[VSE Client]: socket read ready,..");
#endif
}

void LocalSocketIpcClient::socket_error(QLocalSocket::LocalSocketError error)
{
#if QT_DEBUG
  QString message;
  if (error == QAbstractSocket::ConnectionRefusedError) {
    message = "connection was refused by the peer (or timed out).";
  } else if (error == QAbstractSocket::RemoteHostClosedError) {
    message = "remote socket closed the connection. Note that the client socket (i.e., this socket) will be closed after the remote close notification has been sent.";
  } else if (error == QAbstractSocket::HostNotFoundError) {
    message = "local socket name was not found.";
  } else if (error == QAbstractSocket::SocketAccessError) {
    message = "socket operation failed because the application lacked the required privileges.";
  } else if (error == QAbstractSocket::SocketResourceError) {
    message = "local system ran out of resources (e.g., too many sockets).";
  } else if (error == QAbstractSocket::SocketTimeoutError) {
    message = "socket operation timed out.";
  } else if (error == QAbstractSocket::DatagramTooLargeError) {
    message = "datagram was larger than the operating system's limit (which can be as low as 8192 bytes).";
  } else if (error == QAbstractSocket::NetworkError) {
    message = "An error occurred with the connection.";
  }
  if (error == QAbstractSocket::UnsupportedSocketOperationError) {
    message = "requested socket operation is not supported by the local operating system.";
  }
  if (error == QAbstractSocket::OperationError) {
    message = "An operation was attempted while the socket was in a state that did not permit it.";
  }
  if (error == QAbstractSocket::UnknownSocketError) {
    message = "An unidentified error occurred.";
  }
  emit signalWriteLogMessage(0, "[VSE Client]: socket error - " + message);
#else
  Q_UNUSED(error);
#endif
}
