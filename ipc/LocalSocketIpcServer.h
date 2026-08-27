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

/// Inbound command channel from Hybrid. May log through MainWindow - its messages end in the client queue.
class LocalSocketIpcServer : public QObject
{
  Q_OBJECT
  public:
    explicit LocalSocketIpcServer(const QString &servername, QObject *parent);
    ~LocalSocketIpcServer();

    /// False if listen() failed; the caller reports it, nothing is connected to us yet
    bool isListening() const;
    QString errorString() const;

  private:
    QLocalServer* m_server;
    QString m_serverName;
    QLocalSocket* m_clientConnection;

  public slots:
    void socket_new_connection();
    void socket_readReady();
    void socket_disconnected();

  signals:
    void messageReceived(QString message);
    void signalWriteLogMessage(int a_messageType, const QString & a_message);
};

#endif /* HELPER_LOCALSOCKETIPCSERVER_H_ */
