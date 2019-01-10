#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QHostAddress>

#include "network_global.h"

class QTcpServer;
class QTcpSocket;

class NETWORKSHARED_EXPORT TCPServer : public QObject
{
    Q_OBJECT
public:
    explicit TCPServer(QObject *parent = nullptr);
    ~TCPServer();

    bool listen(const QHostAddress &address = QHostAddress::Any, quint16 port = 0);

private slots:
    void onNewConnection();

private:
    QTcpServer *m_pServer;
    QMap<QString, QTcpSocket *> m_mapSocket;
};

#endif // TCPSERVER_H
