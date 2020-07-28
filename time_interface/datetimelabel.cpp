#include "datetimelabel.h"
#include<QString>
#include<QDateTime>
#include<QDebug>
Datetimelabel::Datetimelabel()
{
    this->setText(this->getCurrentTimeString());
    tm=new QTimer(this);//初始化定时
    connect(tm,&QTimer::timeout,this,&Datetimelabel::refreshTime);//建立信号和槽的连接
    tm->start(1);//定时器开始工作
}
QString Datetimelabel:: getCurrentTimeString()
{
    return QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
}
 void Datetimelabel::refreshTime()
{
    this->setText(this->getCurrentTimeString());
 }
 void Datetimelabel::mousePressEvent(QMouseEvent *ev)
{
    if (tm->isActive())
        tm->stop();
    else
        tm->start();
 }
