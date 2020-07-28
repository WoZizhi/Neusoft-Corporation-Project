#ifndef DATETIMELABEL_H
#define DATETIMELABEL_H
#include<QString>
#include<QLabel>
#include<QTimer>

class Datetimelabel:public QLabel//继承
{
public:
    Datetimelabel();
    QString getCurrentTimeString();//声明一个自己的函数
    QTimer *tm;//定时器变量

public slots:
    void refreshTime();//刷新时间
    void onClick();//点击时间处理
protected:
    virtual void mousePressEvent(QMouseEvent *ev);
};

#endif // DATETIMELABEL_H
