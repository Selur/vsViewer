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

LocalSocketIpcServer::LocalSocketIpcServer(QString servername, QObject *parent)
    : QObject(parent)
{
  m_server = new QLocalServer(this);
  if (!m_server->listen(servername)) {
    emit signalWriteLogMessage(mtWarning, QString("Not able to start %1!").arg(servername));
  } else {
    connect(m_server, SIGNAL(newConnection()), this, SLOT(socket_new_connection()));
  }
}

LocalSocketIpcServer::~LocalSocketIpcServer()
{

}

void LocalSocketIpcServer::socket_new_connection()
{

  QLocalSocket *clientConnection = m_server->nextPendingConnection();

  while (clientConnection->bytesAvailable() < (int) sizeof(quint32)) {
    clientConnection->waitForReadyRead();
  }
  connect(clientConnection, SIGNAL(disconnected()), clientConnection, SLOT(deleteLater()));

  QDataStream in(clientConnection);
  in.setVersion(QDataStream::Qt_4_6);
  if (clientConnection->bytesAvailable() < (int) sizeof(quint16)) {
    return;
  }
  QString message;
  in >> message;
  emit messageReceived(message);
}

