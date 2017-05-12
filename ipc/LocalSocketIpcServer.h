/*
 * LocalSocketIpcServer.h
 *
 *  Created on: 19.10.2014
 *      Author: Selur
 */

#ifndef HELPER_LOCALSOCKETIPCSERVER_H_
#define HELPER_LOCALSOCKETIPCSERVER_H_

#include <QObject>
#include <QString>
#include <QLocalServer>
#include <QLocalSocket>

class LocalSocketIpcServer : public QObject
{
  Q_OBJECT
  public:
    LocalSocketIpcServer(QString servername, QObject *parent);
    ~LocalSocketIpcServer();

  private:
    QLocalServer* m_server;
    QString m_serverName;
    QLocalSocket* m_clientConnection;
    void currentState(QLocalSocket::LocalSocketState state);

  public slots:
    void socket_new_connection();
    void socket_readReady();
    void socket_disconnected();

  signals:
    void messageReceived(QString message);
    void signalWriteLogMessage(int a_messageType, const QString & a_message);
};

#endif /* HELPER_LOCALSOCKETIPCSERVER_H_ */
