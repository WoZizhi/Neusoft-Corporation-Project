#include "mainwindow.h"
#include <QApplication>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QWidget>
#include <QTimer>

int ecgData []=
{
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2008, 2016, 2016, 2016, 2024, 2032, 2048,
    2064, 2064, 2064, 2072, 2080, 2080, 2080, 2088, 2096, 2104,
    2112, 2112, 2112, 2112, 2112, 2112, 2104, 2096, 2088,
    2080, 2080, 2080, 2072, 2064, 2064, 2064, 2048, 2032, 2032,
    2032, 2016, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 1992, 1984, 1976,
    1968, 1960, 1952, 1944, 1936, 1944, 1952, 2016, 2080, 2136,
    2192, 2256, 2320, 2376, 2432, 2488, 2544, 2568, 2592, 2536,
    2480, 2424, 2368, 2304, 2240, 2184, 2128, 2072, 2016, 1968,
    1920, 1928, 1936, 1944, 1952, 1960, 1968, 1984, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2008, 2016, 2024, 2032, 2032,
    2032, 2048, 2064, 2064, 2064, 2072, 2080, 2088, 2096, 2104,
    2112, 2112, 2112, 2120, 2128, 2136, 2144, 2152, 2160, 2160,
    2160, 2160, 2160, 2168, 2176, 2176, 2176, 2184, 2192,
    2192, 2192, 2192, 2200, 2208, 2208, 2208, 2208, 2208, 2208,
    2208, 2200, 2192, 2192, 2192, 2184, 2176, 2176, 2176, 2168,
    2160, 2160, 2160, 2144, 2128, 2128, 2128, 2128, 2128, 2112,
    2096, 2088, 2080, 2072, 2064, 2064, 2064, 2048, 2032, 2024,
    2016, 2016, 2016, 2008, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000
};

class QWidgetSerialTx: public QWidget
{
public:
    QWidgetSerialTx(QWidget *parent=nullptr):QWidget(parent)
    {
        if(0 != this->serialInit())
        {
            qDebug()<<"SerialInit error";
            return;
        }
        timer = new QTimer();
        connect(timer, &QTimer::timeout, this, &QWidgetSerialTx::sendEcgPkg);
        timer->start(2);//每秒钟500个数据
    }
public:
    QSerialPort *com;
    QTimer *timer;
    int ecgDataIndex = 0;
public:
    //char bccCheck(char *data,int len);//校验和检查
    int serialInit(void);//初始化串口
public slots:
    void sendEcgPkg();//发送数据包
};

int QWidgetSerialTx::serialInit(void)
{
    //打印串口信息
    //foreach:标准C++中没有这个关键字
    //qt自己实现了这个关键字，如下会遍历availablePorts，并把每个结果依次赋值给info，类似于for
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        qDebug()<<"Name:"<<info.portName();
        qDebug()<<"Description:"<<info.description();
        qDebug()<<"Manufacturer:"<<info.manufacturer();
        qDebug()<<"Serial Number:"<<info.serialNumber();
    }//执行完应该在应用程序输出位置看到串口数据，需要先启动串口模拟器，并创建串口

    //创建串口对象，在头文件中定义了指针
    com = new QSerialPort();
    //配置串口，根据串口号自行选择
    com->setPortName("COM2");
    //尝试打开串口
    if(!com->open(QIODevice::ReadWrite))
    {
        qDebug("serial open err");
        return -1;//程序中的返回值，一般正常返回0，异常返回非0
    }
    else
    {
        qDebug()<<"serial open success!"<<com->portName();
    }

    //配置串口参数
    //波特率为115200，每秒钟发射115200bit，双向波特率均一致
    com->setBaudRate(QSerialPort::Baud115200, QSerialPort::AllDirections);
    //数据位
    com->setDataBits(QSerialPort::Data8);
    //流程=无
    com->setFlowControl(QSerialPort::NoFlowControl);
    //校验位=无
    com->setParity(QSerialPort::NoParity);
    //停止位=1
    com->setStopBits(QSerialPort::OneStop);

    return 0;
}

void QWidgetSerialTx::sendEcgPkg()
{
//    char dataBuf[10]={(char)0x01,(char)0x02,(char)0x03,(char)0x04,(char)0x01,(char)0x02,(char)0x03,(char)0x04,
//                      (char)0x05,(char)0xFF};
//    this->com->write(dataBuf, sizeof(dataBuf));
    char dataBuf[10];
    unsigned int ecg[3]={2048,2048,2048};
    int i;

    int len = (int)sizeof(ecgData)/sizeof(int);
    //取ECG2数据
    if(ecgDataIndex >= len)
        ecgDataIndex = 0;
    ecg[1]=ecgData[ecgDataIndex++];

    //封包
    dataBuf[0] = 0x08;
    dataBuf[1] = 0x80;
    //qDebug("%02X %02X",ecg[1]&0x80,ecg[1]&0x8000);
    //qDebug("%02X %02X",(ecg[1]&0x80>>(7-i*2-1),(ecg[1]&0x8000>>(15-i*2))));
    for(i=0;i<3;i++)
    {
        dataBuf[1] = dataBuf[1] | ((ecg[i]&0x80)>>(7-i*2-1));
        dataBuf[1] = dataBuf[1] | ((ecg[i]&0x8000)>>(15-i*2));
        dataBuf[i*2+3] = 0x80 | (ecg[i]&0x7F);
        dataBuf[i*2+2] = 0x80 | ((ecg[i]>>8) & 0x7F);
    }
    dataBuf[8] = 0x80;      //ECG状态位
    dataBuf[9] = 0xFF;      //校验位

    this->com->write(dataBuf, sizeof(dataBuf));
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    QWidgetSerialTx *com = new QWidgetSerialTx();

    return a.exec();
}

