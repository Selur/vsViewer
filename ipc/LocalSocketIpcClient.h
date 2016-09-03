/*
 * LocalSocketIpcClient.h
 *
 *  Created on: 19.10.2014
 *      Author: Selur
 */

#ifndef LOCALSOCKETIPCCLIENT_H_
#define LOCALSOCKETIPCCLIENT_H_

#include <QObject>
#include <QString>
#include <QLocalSocket>

class LocalSocketIpcClient : public QObject
{
  Q_OBJECT
  public:
    LocalSocketIpcClient(QString remoteServername, QObject *parent = 0);
    ~LocalSocketIpcClient();

  private:
    QLocalSocket* m_socket;
    quint16 m_blockSize;
    QString m_message;
    QString m_serverName;

  public slots:
    void send_MessageToServer(QString message);

    void socket_connected();
    void socket_disconnected();

    void socket_readReady();
    void socket_error(QLocalSocket::LocalSocketError);
};

#endif /* LOCALSOCKETIPCCLIENT_H_ */
