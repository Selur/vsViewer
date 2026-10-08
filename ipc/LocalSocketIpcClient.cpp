/*
 * LocalSocketIpcClient.cpp
 *
 *  Created on: 19.10.2014
 *      Author: Selur
 */

#include "LocalSocketIpcClient.h"

#include <QDataStream>
#include <QDateTime>

#ifdef QT_DEBUG
#include <iostream>
#endif

LocalSocketIpcClient::LocalSocketIpcClient(const QString& remoteServername, QObject *parent)
    : QObject(parent), m_lastConnectAttemptMs(-1)
{
  m_socket = new QLocalSocket(this);
  m_serverName = remoteServername;

  connect(m_socket, SIGNAL(connected()), this, SLOT(socket_connected()));
  connect(m_socket, SIGNAL(disconnected()), this, SLOT(socket_disconnected()));

  connect(m_socket, SIGNAL(readyRead()), this, SLOT(socket_readReady()));
#if (QT_VERSION < QT_VERSION_CHECK(6, 0, 0))
  connect(m_socket, SIGNAL(error(QLocalSocket::LocalSocketError)), this, SLOT(socket_error(QLocalSocket::LocalSocketError)));
#else
  connect(m_socket, SIGNAL(errorOccurred(QLocalSocket::LocalSocketError)), this, SLOT(socket_error(QLocalSocket::LocalSocketError)));
#endif
}

LocalSocketIpcClient::~LocalSocketIpcClient()
{
  // best-effort last flush: queued messages would otherwise be dropped by abort()
  if (m_socket->state() == QLocalSocket::ConnectedState) {
    this->flushPending();
    // Destroying the socket cancels a pending overlapped write, so the last messages need
    // this - but only when something really is outstanding: with the event loop already
    // stopped waitForBytesWritten() cannot complete and burns its whole timeout, so keep it short.
    if (m_socket->bytesToWrite() > 0) m_socket->waitForBytesWritten(1000);
  }
  m_socket->abort();
  delete m_socket;
  m_socket = nullptr;
}

// status messages are advisory - never let an absent peer grow the queue forever
static const int MAX_PENDING_MESSAGES = 100;
// don't re-attempt a failed connect on every single message
static const qint64 CONNECT_RETRY_INTERVAL_MS = 5000;

void LocalSocketIpcClient::send_MessageToServer(QString message)
{
  m_pending.append(message);
  while (m_pending.size() > MAX_PENDING_MESSAGES) {
    m_pending.removeFirst();
  }
  if (m_socket->state() == QLocalSocket::ConnectedState) {
    this->flushPending();
    return;
  }
  this->tryConnect();
}

// connect at most once every CONNECT_RETRY_INTERVAL_MS; connectToServer() itself blocks on a busy pipe
void LocalSocketIpcClient::tryConnect()
{
  if (m_socket->state() != QLocalSocket::UnconnectedState) {
    return; // already connecting, nothing to do but wait
  }
  const qint64 now = QDateTime::currentMSecsSinceEpoch();
  if (m_lastConnectAttemptMs >= 0 && (now - m_lastConnectAttemptMs) < CONNECT_RETRY_INTERVAL_MS) {
    return; // a recent attempt failed, keep queueing instead of blocking again
  }
  m_lastConnectAttemptMs = now;
  m_socket->connectToServer(m_serverName);
}

void LocalSocketIpcClient::flushPending()
{
  if (m_socket->state() != QLocalSocket::ConnectedState) {
    return;
  }
  while (!m_pending.isEmpty()) {
    const QString message = m_pending.takeFirst();
#ifdef QT_DEBUG
    std::cout << "[VSE Client]: sending message " << qPrintable(message) << std::endl;
#endif
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);
    out << message.toUtf8();
    m_socket->write(block);
  }
  m_socket->flush();
}

void LocalSocketIpcClient::socket_connected()
{
#ifdef QT_DEBUG
  if (m_pending.isEmpty()) {
    std::cout << "[VSE Client]: connected, nothing to send,.." << std::endl;
  }
#endif
  this->flushPending();
}

void LocalSocketIpcClient::socket_disconnected()
{
#ifdef QT_DEBUG
  std::cout << "[VSE Client]: socket_disconnected" << std::endl;
#endif
}

void LocalSocketIpcClient::socket_readReady()
{
#ifdef QT_DEBUG
  std::cout << "[VSE Client]: socket_readReady" << std::endl;
#endif
}

void LocalSocketIpcClient::socket_error(QLocalSocket::LocalSocketError error)
{
#ifdef QT_DEBUG
  QString message;
  if (error == QLocalSocket::ConnectionRefusedError) {
    message = QString("connection was refused by the peer (or timed out).");
  } else if (error == QLocalSocket::SocketAccessError) {
    message = QString("socket operation failed because the application lacked the required privileges.");
  } else if (error == QLocalSocket::SocketResourceError) {
    message = QString("local system ran out of resources (e.g., too many sockets).");
  } else if (error == QLocalSocket::SocketTimeoutError) {
    message = QString("socket operation timed out.");
  } else if (error == QLocalSocket::DatagramTooLargeError) {
    message = QString("datagram was larger than the operating system's limit (which can be as low as 8192 bytes).");
  } else if (error == QLocalSocket::UnsupportedSocketOperationError) {
    message = QString("requested socket operation is not supported by the local operating system.");
  } else if (error == QLocalSocket::OperationError) {
    message = QString("An operation was attempted while the socket was in a state that did not permit it.");
  } else if (error == QLocalSocket::UnknownSocketError) {
    message = QString("An unidentified error occurred.");
  } else {
    message = QString("Unknown");
  }
  std::cout << "[VSE Client]: socket error: " << qPrintable(message) << std::endl;
#else
  Q_UNUSED(error)
#endif
}
