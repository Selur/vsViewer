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
#include <QStringList>
#include <QLocalSocket>

/// Outbound status channel to Hybrid. No log signal on purpose - it recursed to a stack overflow (docs/issues.md #1).
class LocalSocketIpcClient : public QObject
{
  Q_OBJECT
  public:
    explicit LocalSocketIpcClient(const QString& remoteServername, QObject *parent = nullptr);
    ~LocalSocketIpcClient();

  private:
    QLocalSocket* m_socket;
    QStringList m_pending; // queued while the connection is still being established
    QString m_serverName;
    qint64 m_lastConnectAttemptMs; // -1 = never tried; used to back off failed connects

    void flushPending();
    void tryConnect();

  public slots:
    void send_MessageToServer(QString message);

    void socket_connected();
    void socket_disconnected();

    void socket_readReady();
    void socket_error(QLocalSocket::LocalSocketError);
};

#endif /* LOCALSOCKETIPCCLIENT_H_ */
