#include <QApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tcpserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    TcpServer *mTcpServer = new TcpServer("127.0.0.1",10086,&w);
    w.show();
    return a.exec();
}
