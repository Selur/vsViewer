/*
 * LocalSocketIpcServer.cpp
 *
 *  Created on: 19.10.2014
 *      Author: Selur
 */

#include "LocalSocketIpcServer.h"

#include <QDataStream>

namespace
{
const char * socketStateName(QLocalSocket::LocalSocketState state)
{
  switch (state) {
    case QLocalSocket::UnconnectedState: return "UnconnectedState";
    case QLocalSocket::ConnectingState:  return "ConnectingState";
    case QLocalSocket::ConnectedState:   return "ConnectedState";
    case QLocalSocket::ClosingState:     return "ClosingState";
  }
  return "UnknownState";
}
}

LocalSocketIpcServer::LocalSocketIpcServer(const QString& servername, QObject *parent)
    : QObject(parent), m_server(nullptr), m_serverName(servername), m_clientConnection(nullptr)
{
  m_server = new QLocalServer(this);
  if (!m_server->listen(m_serverName)) {
    // clear a stale socket left by a crash; only on failure, so a live server keeping the name is never unlinked
    QLocalServer::removeServer(m_serverName);
    if (m_server->listen(m_serverName)) {
      connect(m_server, SIGNAL(newConnection()), this, SLOT(socket_new_connection()));
    }
    // the caller reports failure - nothing is connected to our log signal yet
    return;
  }
  connect(m_server, SIGNAL(newConnection()), this, SLOT(socket_new_connection()));
}

bool LocalSocketIpcServer::isListening() const { return m_server != nullptr && m_server->isListening(); }

QString LocalSocketIpcServer::errorString() const { return m_server == nullptr ? QString() : m_server->errorString(); }

LocalSocketIpcServer::~LocalSocketIpcServer()
{
  if (m_server == nullptr) {
    return;
  }
  m_server->close();
  m_server->disconnect();
  m_server->deleteLater();
  m_server = nullptr;
}

void LocalSocketIpcServer::socket_new_connection()
{
#ifdef QT_DEBUG
  emit signalWriteLogMessage(0, "[VSE Server]: incoming connection");
#endif

  QLocalSocket* incoming = m_server->nextPendingConnection();
  if (incoming == nullptr) {
    return;
  }
#ifdef QT_DEBUG
  emit signalWriteLogMessage(0, QString("[VSE Server]: ") + socketStateName(incoming->state()));
#endif
  // newest connection wins; the previous one used to be dropped without being closed
  if (m_clientConnection != nullptr) {
    m_clientConnection->disconnect(this); // don't let close() re-enter socket_disconnected()
    m_clientConnection->close();
    m_clientConnection->deleteLater();
  }
  m_clientConnection = incoming;
  connect(m_clientConnection, SIGNAL(disconnected()), this, SLOT(socket_disconnected()));
  connect(m_clientConnection, SIGNAL(readyRead()), this, SLOT(socket_readReady()));
}

void LocalSocketIpcServer::socket_disconnected()
{
  if (m_clientConnection == nullptr) {
    return;
  }
  m_clientConnection->close();
  m_clientConnection->deleteLater();
  m_clientConnection = nullptr;
}

void LocalSocketIpcServer::socket_readReady()
{
  if (m_clientConnection == nullptr) {
    emit signalWriteLogMessage(0, "[VSE Server]: socket_readReady no client connection");
    return;
  }
#ifdef QT_DEBUG
  emit signalWriteLogMessage(0, "[VSE Server]: socket is ready to be read");
  emit signalWriteLogMessage(0, QString("[VSE Server]: connection open: ") + (m_clientConnection->isOpen() ? "true" : "false"));
  emit signalWriteLogMessage(0, QString("[VSE Server]: connection readable: ") + (m_clientConnection->isReadable() ? "true" : "false"));
#endif

  // messageReceived() can close or replace the connection - hold on to what we read from
  QLocalSocket * const connection = m_clientConnection;
  QDataStream in(connection);
  in.setVersion(QDataStream::Qt_5_5);
  // a transaction rolls the read back until a whole message arrived; a split one used to decode as empty
  forever {
    in.startTransaction();
    QByteArray message;
    in >> message;
    if (!in.commitTransaction()) {
      return; // incomplete - wait for the rest to turn up
    }
#ifdef QT_DEBUG
    emit signalWriteLogMessage(0, "[VSE Server] - Message received: " + QString::fromUtf8(message));
#endif
    emit messageReceived(QString::fromUtf8(message));
    if (m_clientConnection != connection) {
      return; // a slot closed or replaced the connection underneath us
    }
  }
}
