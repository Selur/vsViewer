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
    explicit LocalSocketIpcClient(const QString& remoteServername, QObject *parent = nullptr);
    ~LocalSocketIpcClient();

  private:
    QLocalSocket* m_socket;
    quint16 m_blockSize;
    QString m_message;
    QString m_serverName;

  public slots:
    void send_MessageToServer(const QString &message);

    void socket_connected();
    void socket_disconnected();

    void socket_readReady();
    void socket_error(QLocalSocket::LocalSocketError);

  signals:
    void signalWriteLogMessage(int a_messageType, const QString & a_message);
};

#endif /* LOCALSOCKETIPCCLIENT_H_ */
