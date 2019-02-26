#include <QDebug>
#include <QTcpSocket>

#include "tcpclient.h"

TCPClient::TCPClient(QObject *parent) :
    QObject(parent),
    m_pSocket(nullptr)
{
    m_pSocket = new QTcpSocket(this);
}

TCPClient::~TCPClient()
{
}

void TCPClient::connectToHost(const QString &address, quint16 port)
{
    if(m_pSocket == nullptr)
        return;
    m_pSocket->connectToHost(QHostAddress::LocalHost, port);
    qDebug() << QString("connect to %1:%2").arg(address).arg(port);
}

void TCPClient::write(const char *p, qint64 len)
{
    if(m_pSocket == nullptr)
        return;
    m_pSocket->write(p, len);
}
