#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QDebug>
#include <QMessageBox>
#include <QMetaType>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <QPainter>
#include <QPixmap>
#include <QPen>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#define SOCKETCLIENTBUFSIZE 1024

class TcpServer:public QWidget
        // 必须继承QWidget，否则无法使用connect
{
    Q_OBJECT
public:
    int pointX=0;
    int pointY=0;
    int pointY_old=0;

    QTcpServer* mQTcpServer;
    QTcpSocket* mSocketClient;

    TcpServer(QString ip,quint16 port,MainWindow *w);
    MainWindow *win;
    void drawwaves(float num);
//    TcpServer();
private slots:
    void acceptConnection();
    void readClient();
private:

};

#endif // TCPSERVER_H
