#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>


class TcpClient : public QWidget
{
    Q_OBJECT
public:
    int dip = 0;

    explicit TcpClient(QWidget *parent = nullptr);
    TcpClient(QString ip,qint16 port);
    QTimer *timer;
    void sendwaves();
    void closesocket(TcpClient Client);
    QTcpSocket *mClient;
private:


};

#endif // TCPCLIENT_H
