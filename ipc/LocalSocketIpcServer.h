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

class LocalSocketIpcServer : public QObject
{
  Q_OBJECT
  public:
    LocalSocketIpcServer(QString servername, QObject *parent);
    ~LocalSocketIpcServer();

  private:
    QLocalServer* m_server;
    QString m_serverName;

  public slots:
    void socket_new_connection();

  private slots:
    void deleteClient(QLocalSocket *clientConnection);

  signals:
    void messageReceived(QString message);
    void signalWriteLogMessage(int a_messageType, const QString & a_message);

};

#endif /* HELPER_LOCALSOCKETIPCSERVER_H_ */
