/*
 * LocalSocketIpcServer.cpp
 *
 *  Created on: 19.10.2014
 *      Author: Selur
 */

#include "LocalSocketIpcServer.h"
#include <QDataStream>

LocalSocketIpcServer::LocalSocketIpcServer(const QString& servername, QObject *parent)
    : QObject(parent), m_serverName(servername), m_clientConnection(nullptr)
{
  m_server = new QLocalServer(this);
  for (int i = 0; i < 10; ++i) {
    if (m_server->listen(m_serverName)) {
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
  emit signalWriteLogMessage(0, "[VSE Server]: incoming connection");
  m_clientConnection = m_server->nextPendingConnection();
  this->currentState(m_clientConnection->state());
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
#include <iostream>
void LocalSocketIpcServer::socket_readReady()
{
  if (m_clientConnection == nullptr) {
    emit signalWriteLogMessage(0, "[VSE Server]: socket_readReady no client connection");
    return;
  }
  emit signalWriteLogMessage(0, "[VSE Server]: socket is ready to be read");
  emit signalWriteLogMessage(0, "[VSE Server]: connection open: " + QString(m_clientConnection->isOpen() ? "true" : "false"));
  emit signalWriteLogMessage(0, "[VSE Server]: connection readable: " + QString(m_clientConnection->isReadable() ?  "true" : "false"));
  QDataStream in(m_clientConnection);
  in.setVersion(QDataStream::Qt_5_5);
  try {
    while (m_clientConnection != nullptr && m_clientConnection->bytesAvailable() >= int(sizeof(quint16))) {
      QByteArray message;
      in >> message;
      emit signalWriteLogMessage(0, "[VSE Server] - Message received: " + message);
      emit messageReceived(message);
    }
  } catch (...) {
    std::cout << "[VSE Server]: Problem with client connection,..." << std::endl;
    m_clientConnection = nullptr;
  }


}




