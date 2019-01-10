#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

#include "tcpserver.h"

TCPServer::TCPServer(QObject *parent) :
    QObject(parent),
    m_pServer(nullptr)
{
    m_pServer = new QTcpServer(this);
    connect(m_pServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

TCPServer::~TCPServer()
{
    delete m_pServer;
}

bool TCPServer::listen(const QHostAddress &address, quint16 port)
{
    if(m_pServer == nullptr)
        return false;
    return m_pServer->listen(address, port);
}

void TCPServer::onNewConnection()
{
    QTcpSocket *pSocket = m_pServer->nextPendingConnection();
    if(pSocket != nullptr && pSocket->isValid())
    {
        m_mapSocket.insert(QString("%1:%2").arg(pSocket->peerAddress().toString()).arg(pSocket->peerPort()), pSocket);
        qDebug() << "new connection";
    }
}
