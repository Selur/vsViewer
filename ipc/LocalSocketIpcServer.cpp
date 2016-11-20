/*
 * LocalSocketIpcServer.cpp
 *
 *  Created on: 19.10.2014
 *      Author: Selur
 */

#include "LocalSocketIpcServer.h"
#include <QLocalSocket>
#include <QDataStream>
#include <vapoursynth/VapourSynth.h>
#include <QMessageBox>

LocalSocketIpcServer::LocalSocketIpcServer(QString servername, QObject *parent)
    : QObject(parent), m_serverName(servername)
{
  m_server = new QLocalServer(this);
  if (!m_server->listen(m_serverName)) {
    emit signalWriteLogMessage(mtWarning, QString("Not able to start %1!").arg(m_serverName));
  } else {
    connect(m_server, SIGNAL(newConnection()), this, SLOT(socket_new_connection()));
  }
}

LocalSocketIpcServer::~LocalSocketIpcServer()
{
}

void LocalSocketIpcServer::deleteClient(QLocalSocket *clientConnection)
{
 clientConnection->close();
}

void LocalSocketIpcServer::socket_new_connection()
{
  QLocalSocket *clientConnection = m_server->nextPendingConnection();
  while (clientConnection != nullptr) {
    while (clientConnection->bytesAvailable() < (int) sizeof(quint32)) {
      clientConnection->waitForReadyRead();
    }
    connect(clientConnection, SIGNAL(disconnected()), clientConnection, SLOT(deleteClient()));

    QDataStream in(clientConnection);
    in.setVersion(QDataStream::Qt_4_6); //TODO: adjust once QT 4.6 support is dropped
    if (clientConnection->bytesAvailable() < (int) sizeof(quint16)) {
      return;
    }
    QString message;
    in >> message;
    emit messageReceived(message);
    clientConnection = m_server->nextPendingConnection();
  }
  m_server->close();
  m_server->deleteLater();
  m_server = new QLocalServer(this);
  if (!m_server->listen(m_serverName)) {
    emit signalWriteLogMessage(mtWarning, QString("Not able to start %1!").arg(m_serverName));
  } else {
    connect(m_server, SIGNAL(newConnection()), this, SLOT(socket_new_connection()));
  }
}

