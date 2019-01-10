#ifndef QTCPCLIENT_H
#define QTCPCLIENT_H

#include <QHostAddress>
#include <QObject>

#include "network_global.h"

class QTcpSocket;

class NETWORKSHARED_EXPORT TCPClient : public QObject
{
    Q_OBJECT
public:
    explicit TCPClient(QObject *parent = nullptr);
    ~TCPClient();

    void connectToHost(const QString &address, quint16 port);

private:
    QTcpSocket *m_pSocket;
};

#endif // QTCPCLIENT_H
