#include "tcpclient.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    TCPClient *c = new TCPClient();
    c->connectToHost("localhost", 6666);
}

MainWindow::~MainWindow()
{
    delete ui;
}
