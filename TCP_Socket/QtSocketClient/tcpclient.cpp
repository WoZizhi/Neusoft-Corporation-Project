#include "tcpclient.h"
int ecgWave[] = {


    1936, 1944, 1952, 2016, 2080, 2136,
    2192, 2256, 2320, 2376, 2432, 2488, 2544, 2568, 2592, 2536,
    2480, 2424, 2368, 2304, 2240, 2184, 2128, 2072, 2016, 1968,
    1920, 1928, 1936

    };

TcpClient::TcpClient(QWidget *parent) : QWidget(parent)
{
    mClient = new QTcpSocket(); // 构建QTcpSocket实例
    mClient->connectToHost(QHostAddress::LocalHost,10086); //连接本地端口10086
    mClient->waitForConnected();
//    if (mClient->waitForConnected()) // 等待连接建立
//    {
//        tx_buf += mClient->peerAddress().toString(); // 将连接的另一端的地址转为字符串的形式，放入发送缓存区
//        tx_buf += ":"; // 放入间隔字符
//        tx_buf += QString::number(mClient->peerPort()); // 将整型数形式的端口号，转为字符串的形式，放入发送缓冲区
//        mClient->write(tx_buf.toUtf8()); //将发送缓冲区转换为utf8编码发送出去
//    }
    timer = new QTimer(parent);
    // 定时器timeout信号与时间刷新函数进行绑定/关联
    // 信号与槽机制实现
    connect(timer, &QTimer::timeout, this, &TcpClient::sendwaves);
    timer->start(10); //1000ms
}
void TcpClient::sendwaves()
{
        QString tx_buf =  QString::number(ecgWave[dip]); // 初始化发送缓冲区
        mClient->write(tx_buf.toUtf8()); //将发送缓冲区转换为utf8编码发送出去
        dip++;
        if(dip>=sizeof(ecgWave)/sizeof(int))
            dip =0;
}

TcpClient::TcpClient(QString ip,qint16 port)
{
    mClient = new QTcpSocket(); // 构建QTcpSocket实例
    mClient->connectToHost(QHostAddress::LocalHost,port); //连接本地端口10086
    mClient->waitForConnected();
//    if (mClient->waitForConnected()) // 等待连接建立
//    {
//        tx_buf += mClient->peerAddress().toString(); // 将连接的另一端的地址转为字符串的形式，放入发送缓存区
//        tx_buf += ":"; // 放入间隔字符
//        tx_buf += QString::number(mClient->peerPort()); // 将整型数形式的端口号，转为字符串的形式，放入发送缓冲区
//        mClient->write(tx_buf.toUtf8()); //将发送缓冲区转换为utf8编码发送出去
//    }
    timer = new QTimer();
    // 定时器timeout信号与时间刷新函数进行绑定/关联
    // 信号与槽机制实现
    connect(timer, &QTimer::timeout, this, &TcpClient::sendwaves);
    timer->start(10); //1000ms
}

void TcpClient::closesocket(TcpClient Client)
{
//    foreach (QTcpSocket* socket, connection_list)
//    {
//        socket->close();
//        socket->deleteLater();
//    }

//    Client->close();
//    Client->deleteLater();

}
