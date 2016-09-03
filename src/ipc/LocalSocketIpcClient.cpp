/*
 * LocalSocketIpcClient.cpp
 *
 *  Created on: 19.10.2014
 *      Author: Selur
 */

#include "LocalSocketIpcClient.h"
#include <iostream>
#include <QDataStream>

LocalSocketIpcClient::LocalSocketIpcClient(QString remoteServername, QObject *parent)
    : QObject(parent), m_blockSize(0)
{
  m_socket = new QLocalSocket(this);
  m_serverName = remoteServername;

  connect(m_socket, SIGNAL(connected()), this, SLOT(socket_connected()));
  connect(m_socket, SIGNAL(disconnected()), this, SLOT(socket_disconnected()));

  connect(m_socket, SIGNAL(readyRead()), this, SLOT(socket_readReady()));
  connect(m_socket, SIGNAL(error(QLocalSocket::LocalSocketError)), this,
      SLOT(socket_error(QLocalSocket::LocalSocketError)));
}

LocalSocketIpcClient::~LocalSocketIpcClient()
{
  m_socket->abort();
  delete m_socket;
  m_socket = nullptr;
}

void LocalSocketIpcClient::send_MessageToServer(QString message)
{
  m_socket->abort();
  m_message = message;
  m_socket->connectToServer(m_serverName);
}

void LocalSocketIpcClient::socket_connected()
{
  QByteArray block;
  QDataStream out(&block, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_4_6);
  out << m_message;
  out.device()->seek(0);
  m_socket->write(block);
  m_socket->flush();
}

void LocalSocketIpcClient::socket_disconnected()
{
  std::cout << "VSE - socket_disconnected" << endl;
}

void LocalSocketIpcClient::socket_readReady()
{
  std::cout << "VSE - socket_readReady" << endl;
}

void LocalSocketIpcClient::socket_error(QLocalSocket::LocalSocketError error)
{
  std::cerr << "VSE - socket_error: " << error << endl;
}
