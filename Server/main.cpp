#include <QCoreApplication>

#include "tcpserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TCPServer *s = new TCPServer();
    qDebug() << "listen : " << s->listen(QHostAddress::Any, 6666);

    return a.exec();
}
