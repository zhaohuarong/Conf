#include "imageview.h"
#include "usbcamera.h"
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

    USBCamera *pCamera = new USBCamera(this);
    pCamera->start();

    connect(pCamera, SIGNAL(sigImage(QImage)), ui->localView, SLOT(setImage(QImage)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
