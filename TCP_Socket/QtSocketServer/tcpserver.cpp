#include "tcpserver.h"




TcpServer::TcpServer(QString ip,quint16 port,MainWindow *w)
{
    mQTcpServer = new QTcpServer(); // 构造QTcpServer
    win=w;
    if(mQTcpServer->listen(QHostAddress(ip), port))// 监听本机port端口
    {
       connect(mQTcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));

       qDebug()<<"Server is listening on "<<QString::number(port);
    }
    else
    {
        QMessageBox::critical(this,"QTCPServer",QString("Unable to start the server: %1.").arg(mQTcpServer->errorString())); // 报错
        exit(EXIT_FAILURE);
    }
}
//TcpServer::TcpServer()
//{
//    mQTcpServer = new QTcpServer(); // 构造QTcpServer

////    mQTcpServer->listen(QHostAddress::Any, 10086); // 此句注释去掉可以触发报错
////    QMessageBox::information(this, "---提示---", QStringLiteral("正在监听端口10086")); // 编码乱码演示
//    if(mQTcpServer->listen(QHostAddress::LocalHost, 10086))// 监听本机10086端口
//    {
//       connect(mQTcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));

//       qDebug()<<"Server is listening on 10086";
//    }
//    else
//    {
//        QMessageBox::critical(this,"QTCPServer",QString("Unable to start the server: %1.").arg(mQTcpServer->errorString())); // 报错
//        exit(EXIT_FAILURE);
//    }
//}
void TcpServer::acceptConnection()
{
    mSocketClient = mQTcpServer->nextPendingConnection();
    qDebug()<<"Connection Accepted! From IP"<<mSocketClient->peerAddress().toString()<<" Port"<<mSocketClient->peerPort();
    connect(mSocketClient, SIGNAL(readyRead()), this, SLOT(readClient()));
}
void TcpServer::readClient()
{
//    这种方法接收，可能一次无法接收完全，而且需要考虑缓冲区大小的设定
//    char rxbuf[SOCKETCLIENTBUFSIZE] = {0}; // 接收缓冲区
//    mSocketClient->read(rxbuf,SOCKETCLIENTBUFSIZE); // 把客户端接收到的信息，读入rxbuf
//    qDebug()<<QString(rxbuf)<<"+++";

    // 这种方法接收可以收到全部数据
    QByteArray rxbuf = mSocketClient->readAll(); // 取出客户Client中的所有数据
    this->drawwaves(rxbuf.toFloat());
    win->update();
    qDebug()<<QString::fromLocal8Bit(rxbuf); // 打印收到的数据

}
void TcpServer::drawwaves(float num)
{
    QPainter *painter = new QPainter();
    // 启动绘图
    painter->begin(this->win->pixmap);
    // 设置画图参数, 修改画笔颜色，线条粗细
    painter->setPen(QPen(Qt::green,2,Qt::DashDotLine,Qt::RoundCap));

    // 获取窗口尺寸
    int height = this->win->pixmap->height();
    int width = this->win->pixmap->width();
    pointY_old=pointY;
    pointY=(int)((num-2000)/700*(float)height/2+(float)height/2);

    // 擦除历史波形
    painter->save();
    painter->setPen(QPen(Qt::black,8));

    painter->drawLine(pointX+4, 0, pointX+4, height);
    painter->restore();
    if(0!=pointX)
    painter->drawLine(pointX-1, height - pointY_old,pointX, height - pointY);
        pointX = pointX + 1;
    if (pointX > width-6)
        pointX = 0;
    // 绘图结束
    painter->end();
}
