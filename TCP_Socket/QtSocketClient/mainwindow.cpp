#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
//    TcpClient::closesocket(mTcpClient);
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    if(!connectionsendcmd)
    {
        int port = ui->lineEdit->text().toInt();
        qDebug()<<port;
//        ui->pushButton->setText("正在连接");
        mTcpClient = new TcpClient("127.0.0.1",port);
        qDebug()<<QHostAddress(QHostAddress::Any).toString();
        qDebug()<<QHostAddress(QHostAddress::LocalHost).toString();
        ui->pushButton->setChecked(1);
        ui->pushButton->setText("连接");
//        connectionsendcmd=1;
    }
    else
    {
//        connectionsendcmd=0;
//        ui->pushButton->setChecked(0);
//        ui->pushButton->setText("连接");

//        mTcpClient->close();
//        Client->deleteLater();

//        TcpClient::closesocket(mTcpClient);
    }
}
