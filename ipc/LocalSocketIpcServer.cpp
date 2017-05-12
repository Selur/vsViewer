/*
 * LocalSocketIpcServer.cpp
 *
 *  Created on: 19.10.2014
 *      Author: Selur
 */

#include "LocalSocketIpcServer.h"
#include <QDataStream>

LocalSocketIpcServer::LocalSocketIpcServer(QString servername, QObject *parent)
    : QObject(parent), m_serverName(servername), m_clientConnection(nullptr)
{
  m_server = new QLocalServer(this);
  bool started = false;
  for (int i = 0; i < 10; ++i) {
    started = m_server->listen(m_serverName);
    if (started) {
      QObject::connect(m_server, SIGNAL(newConnection()), this, SLOT(socket_new_connection()));
      break;
    }
  }
}

LocalSocketIpcServer::~LocalSocketIpcServer()
{
  m_server->close();
  m_server->deleteLater();
}

void LocalSocketIpcServer::currentState(QLocalSocket::LocalSocketState state)
{
  if (state == QLocalSocket::UnconnectedState) {
    emit signalWriteLogMessage(0, "[VSE Server]: UnconnectedState");
  } else if (state == QLocalSocket::ConnectingState) {
    emit signalWriteLogMessage(0, "[VSE Server]: ConnectingState");
  } else if (state == QLocalSocket::ConnectedState) {
    emit signalWriteLogMessage(0, "[VSE Server]: ConnectedState");
  } else if (state == QLocalSocket::ClosingState) {
    emit signalWriteLogMessage(0, "[VSE Server]: ClosingState");
  }
}

void LocalSocketIpcServer::socket_new_connection()
{
#if QT_DEBUG
  emit signalWriteLogMessage(0, "[VSE Server]: incoming connection");
#endif
  m_clientConnection = m_server->nextPendingConnection();
#if QT_DEBUG
  this->currentState(m_clientConnection->state());
#endif
  QObject::connect(m_clientConnection, SIGNAL(disconnected()), this, SLOT(socket_disconnected()));
  QObject::connect(m_clientConnection, SIGNAL(readyRead()), this, SLOT(socket_readReady()));
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
    return;
  }
#if QT_DEBUG
  emit signalWriteLogMessage(0, "[VSE Server]: socket is ready to be read");
  emit signalWriteLogMessage(0, "[VSE Server]: connection open: " + QString(m_clientConnection->isOpen() ? "true" : "false"));
  emit signalWriteLogMessage(0, "[VSE Server]: connection readable: " + QString(m_clientConnection->isReadable() ?  "true" : "false"));
#endif
  QDataStream in(m_clientConnection);
  in.setVersion(QDataStream::Qt_4_0);
  while (m_clientConnection->bytesAvailable() >= (int) sizeof(quint16)) {
    QString message;
    in >> message;
#if QT_DEBUG
    emit signalWriteLogMessage(0, "[VSE Server] - Message received: " + message);
#endif
    emit messageReceived(message);
  }
}
