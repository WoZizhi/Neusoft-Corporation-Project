#include "mainwindow.h"
#include <QApplication>
#include<QVBoxLayout>
#include<QWidget>
#include<QHBoxLayout>
#include<QLabel>
#include<QDebug>
#include<QPainter>
#include<QColor>
#include"qmath.h"
#include<QPixmap>
#include<QTimer>
#include<QPalette>


const int ecgWave[] = {2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
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
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000};

class QWidgetDraw:public QWidget
{
public:
    int ecgDateIndex;
    qreal index;
    QPixmap *pixmap;

    QWidgetDraw(QWidget *parent=0):QWidget(parent)
   {
       QBasicTimer *timer = new QBasicTimer();
       timer->start(10,this);

       pixmap = new QPixmap(this->width(),this->height());//创建与界面等大小
       pixmap->fill(Qt::black);//设置背景色

       index = 0; //水平方向数据更新位置
       ecgDateIndex = 0;
   }

    virtual void timerEvent(QTimerEvent *event)
   {
       drawWaveTopixmap();
       this->update();
   }

    void drawWaveTopixmap()
   {
      QPainter pixPainter;
      pixPainter.begin(this->pixmap);
      drawEcgWave(&pixPainter);
      pixPainter.end();
   }

    virtual void paintEvent(QPaintEvent *event)
   {
    QPainter *painter=new QPainter();
    qDebug() <<"paintEvent";
    painter->begin(this);
    painter->resetTransform();  //坐标系复位
    painter->drawPixmap(0, 0, *pixmap);
    painter->resetTransform();
    painter->end();
   }

    void drawEcgWave(QPainter *painter)
   {
        QPen pen;
        pen.setWidth(2);
        pen.setColor(QColor("green"));
        painter->setPen(pen);


        //更新绘图参数
        index = index + 1;
        if (index > width())
            index = 1;

        //擦除当前序列
        painter->save();  //保持当前配置
        pen.setColor(Qt::black);
        painter->setPen(pen);
        painter->drawLine(index, 0, index, height());
        painter->restore(); //还原当前配置

        //绘图
        qreal height = this->height();
//        qDebug()<<height/4096 * ecgWave[ecgDateIndex];
//        painter->drawPoint(this->index, height/4096 * ecgWave[ecgDateIndex]);
        QPoint lineStart;
        QPoint lineEnd;
        lineStart.setX(index-1);
        lineEnd.setX(index);

        qreal value=ecgWave[ecgDateIndex];
        int y = round(height/2 - ((value - 2048)/600) * height/2);
        qDebug()<< y;
        lineStart.setY(y);

        ecgDateIndex = ecgDateIndex+ 5;
        if (ecgDateIndex >= sizeof(ecgWave)/sizeof(int))
            ecgDateIndex = 0;
        value=ecgWave[ecgDateIndex];
        y = round(height/2 - ((value - 2048)/600) * height/2);
        lineEnd.setY(y);

        painter->drawLine(lineStart,lineEnd);
   }
};

class ECGWave:public QWidget
{
public:
    ECGWave(QWidget *parent=0):QWidget(parent)
    {
        this->setWindowFlags(Qt::FramelessWindowHint);
        this->setStyleSheet("background-color:black");

        QLabel *title=new QLabel("ECG");
        title->setStyleSheet("color:white");
        QWidgetDraw *waveWin=new  QWidgetDraw();
        QWidget();

        QVBoxLayout *layout=new QVBoxLayout();
        layout->addWidget(title);
        layout->addWidget(waveWin);
        layout->setStretch(0,1);
        layout->setStretch(1,5);
        this->setLayout(layout);
    }
};

class SPO2Wave:public QWidget
{
public:
    SPO2Wave(QWidget *parent=0):QWidget(parent)
    {
        this->setWindowFlags(Qt::FramelessWindowHint);
        this->setStyleSheet("background-color:black");

        QLabel *title=new QLabel("SPO2");
        title->setStyleSheet("color:white");
        QWidgetDraw *waveWin=new  QWidgetDraw();
        QWidget();

        QVBoxLayout *layout=new QVBoxLayout();
        layout->addWidget(title);
        layout->addWidget(waveWin);
        layout->setStretch(0,1);
        layout->setStretch(1,5);
        this->setLayout(layout);
    }
};

class RESPWave:public QWidget
{
public:
    RESPWave(QWidget *parent=0):QWidget(parent)
    {
        this->setWindowFlags(Qt::FramelessWindowHint);
        this->setStyleSheet("background-color:black");

        QLabel *title=new QLabel("RESP");
        title->setStyleSheet("color:white");
        QWidgetDraw *waveWin=new  QWidgetDraw();
        QWidget();

        QVBoxLayout *layout=new QVBoxLayout();
        layout->addWidget(title);
        layout->addWidget(waveWin);
        layout->setStretch(0,1);
        layout->setStretch(1,5);
        this->setLayout(layout);
    }
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    \
    //PART 1
    //创建上面状态栏
    QLabel *title = new QLabel("设备:xd001 备注:001");
    title->setStyleSheet("background-color:rgb(25,25,25)");
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::white);
    title->setPalette(pe);

    //创建三个波形区域
    QWidget *widgetWaveECG=new  ECGWave();
    widgetWaveECG->setStyleSheet("background-color:black");
    QWidget *widgetWaveSPO2=new SPO2Wave();
    widgetWaveSPO2->setStyleSheet("background-color:black");
    QWidget *widgetWaveRESP=new RESPWave();
    widgetWaveRESP->setStyleSheet("background-color:black");
    //波形界面布局
    QVBoxLayout *layoutWave=new QVBoxLayout();
    layoutWave->addWidget(widgetWaveECG);
    layoutWave->addWidget(widgetWaveSPO2);
    layoutWave->addWidget(widgetWaveRESP);

    //右侧温度区域
    //HR区
    QLabel *titleHR = new QLabel("HR");
    titleHR->setStyleSheet("background-color:rgb(25,25,25)");
    QPalette peHR;
    peHR.setColor(QPalette::WindowText,Qt::white);
    titleHR->setPalette(peHR);
    QLabel *textHR1 = new QLabel("  80");
    QLabel *textHR2 = new QLabel("             bmp");
    textHR1->setStyleSheet("font:40px");
    QPalette petextHR1;
    petextHR1.setColor(QPalette::WindowText,Qt::green);
    textHR1->setPalette(petextHR1);
    textHR2->setStyleSheet("font:15px");
    QPalette petextHR2;
    petextHR2.setColor(QPalette::WindowText,Qt::green);
    textHR2->setPalette(petextHR2);

    QVBoxLayout *layouttextHR=new QVBoxLayout();
    layouttextHR->addWidget(textHR2);
    layouttextHR->addWidget(textHR1);
    layouttextHR->setStretch(0,1);
    layouttextHR->setStretch(1,8);

    QVBoxLayout *layoutHR=new QVBoxLayout();
    layoutHR->addWidget(titleHR);
    layoutHR->addLayout(layouttextHR);
    layoutHR->setStretch(0,1);
    layoutHR->setStretch(1,5);

    //ST区
    QLabel *titleST = new QLabel("ST");
    titleST->setStyleSheet("background-color:rgb(25,25,25)");
    QPalette peST;
    peST.setColor(QPalette::WindowText,Qt::white);
    titleST->setPalette(peST);
    QLabel *textST1 = new QLabel("  ST1 -?-");
    QLabel *textST2 = new QLabel("  ST2 -?-");
    QLabel *textST3 = new QLabel("  PVCs -?-");
    textST1->setStyleSheet("font:20px");
    textST2->setStyleSheet("font:20px");
    textST3->setStyleSheet("font:20px");
    QPalette petextST1;
    petextST1.setColor(QPalette::WindowText,Qt::green);
    textST1->setPalette(petextST1);
    QPalette petextST2;
    petextST2.setColor(QPalette::WindowText,Qt::green);
    textST2->setPalette(petextST2);
    QPalette petextST3;
    petextST3.setColor(QPalette::WindowText,Qt::green);
    textST3->setPalette(petextST3);

    QVBoxLayout *layouttextST=new QVBoxLayout();
    layouttextST->addWidget(textST1);
    layouttextST->addWidget(textST2);
    layouttextST->addWidget(textST3);

    QVBoxLayout *layoutST=new QVBoxLayout();
    layoutST->addWidget(titleST);
    layoutST->addLayout(layouttextST);
    layoutST->setStretch(0,1);
    layoutST->setStretch(1,5);

    //NIBP区
    QLabel *titleNIBP = new QLabel("NIBP");
    titleNIBP->setStyleSheet("background-color:rgb(25,25,25)");
    QPalette peNIBP;
    peNIBP.setColor(QPalette::WindowText,Qt::white);
    titleNIBP->setPalette(peNIBP);
    QLabel *textNIBP1 = new QLabel("           00:00:00             mmHg");
    QLabel *textNIBP2 = new QLabel("  -?-  / -?-     -?-");
    textNIBP1->setStyleSheet("font:15px");
    textNIBP2->setStyleSheet("font:30px");
    QPalette petextNIBP1;
    petextNIBP1.setColor(QPalette::WindowText,Qt::blue);
    textNIBP1->setPalette(petextNIBP1);
    QPalette petextNIBP2;
    petextNIBP2.setColor(QPalette::WindowText,Qt::blue);
    textNIBP2->setPalette(petextNIBP2);

    QVBoxLayout *layouttextNIBP=new QVBoxLayout();
    layouttextNIBP->addWidget(textNIBP1);
    layouttextNIBP->addWidget(textNIBP2);
    layouttextNIBP->setStretch(0,1);
    layouttextNIBP->setStretch(1,5);

    QVBoxLayout *layoutNIBP=new QVBoxLayout();
    layoutNIBP->addWidget(titleNIBP);
    layoutNIBP->addLayout(layouttextNIBP);
    layoutNIBP->setStretch(0,1);
    layoutNIBP->setStretch(1,5);

    //SpO2区
    QLabel *titleSpO2 = new QLabel("SpO2");
    titleSpO2->setStyleSheet("background-color:rgb(25,25,25)");
    QPalette peSpO2;
    peSpO2.setColor(QPalette::WindowText,Qt::white);
    titleSpO2->setPalette(peSpO2);
    QLabel *textSpO21 = new QLabel("  98");
    textSpO21->setStyleSheet("font:35px");
    QPalette petextSpO21;
    petextSpO21.setColor(QPalette::WindowText,Qt::red);
    textSpO21->setPalette(petextSpO21);

    QLabel *textSpO22 = new QLabel("       84  bmp");
    textSpO22->setStyleSheet("font:20px");
    QPalette petextSpO22;
    petextSpO22.setColor(QPalette::WindowText,Qt::red);
    textSpO22->setPalette(petextSpO22);

    QLabel *textSpO23 = new QLabel("%");
    textSpO23->setStyleSheet("font:20px");
    QPalette petextSpO23;
    petextSpO23.setColor(QPalette::WindowText,Qt::red);
    textSpO23->setPalette(petextSpO23);

    QHBoxLayout *layouttextSpO21=new QHBoxLayout();
    layouttextSpO21->addWidget(textSpO21);
    layouttextSpO21->addWidget(textSpO23);
    layouttextSpO21->setStretch(0,4);
    layouttextSpO21->setStretch(1,1);

    QVBoxLayout *layouttextSpO2=new QVBoxLayout();
    layouttextSpO2->addLayout(layouttextSpO21);
    layouttextSpO2->addWidget(textSpO22);
    layouttextSpO2->setStretch(0,4);
    layouttextSpO2->setStretch(1,1);

    QVBoxLayout *layoutSpO2=new QVBoxLayout();
    layoutSpO2->addWidget(titleSpO2);
    layoutSpO2->addLayout(layouttextSpO2);
    layoutSpO2->setStretch(0,1);
    layoutSpO2->setStretch(1,5);

    //TEMP区
    QLabel *titleTEMP = new QLabel("TEMP");
    titleTEMP->setStyleSheet("background-color:rgb(25,25,25)");
    QPalette peTEMP;
    peTEMP.setColor(QPalette::WindowText,Qt::white);
    titleTEMP->setPalette(peTEMP);
    QLabel *textTEMP1 = new QLabel("T1 -?-");
    QLabel *textTEMP2 = new QLabel("T2 -?-");
    QLabel *textTEMP3 = new QLabel("TD -?-");
    QLabel *textTEMP4 = new QLabel("                C");
    textTEMP1->setStyleSheet("font:20px");
    textTEMP2->setStyleSheet("font:20px");
    textTEMP3->setStyleSheet("font:20px");
    textTEMP4->setStyleSheet("font:15px");
    QPalette petextTEMP1;
    petextTEMP1.setColor(QPalette::WindowText,Qt::magenta);
    textTEMP1->setPalette(petextTEMP1);
    QPalette petextTEMP2;
    petextTEMP2.setColor(QPalette::WindowText,Qt::magenta);
    textTEMP2->setPalette(petextTEMP2);
    QPalette petextTEMP3;
    petextTEMP3.setColor(QPalette::WindowText,Qt::magenta);
    textTEMP3->setPalette(petextTEMP3);
    QPalette petextTEMP4;
    petextTEMP4.setColor(QPalette::WindowText,Qt::magenta);
    textTEMP4->setPalette(petextTEMP4);

    QVBoxLayout *layouttextTEMP1=new QVBoxLayout();
    layouttextTEMP1->addWidget(textTEMP1);
    layouttextTEMP1->addWidget(textTEMP2);

    QHBoxLayout *layouttextTEMP2=new QHBoxLayout();
    layouttextTEMP2->addLayout(layouttextTEMP1);
    layouttextTEMP2->addWidget(textTEMP3);

    QVBoxLayout *layouttextTEMP=new QVBoxLayout();
    layouttextTEMP->addWidget(textTEMP4);
    layouttextTEMP->addLayout(layouttextTEMP2);
    layouttextTEMP->setStretch(0,1);
    layouttextTEMP->setStretch(1,6);

    QVBoxLayout *layoutTEMP=new QVBoxLayout();
    layoutTEMP->addWidget(titleTEMP);
    layoutTEMP->addLayout(layouttextTEMP);
    layoutTEMP->setStretch(0,1);
    layoutTEMP->setStretch(1,5);

    //RESP区
    QLabel *titleRESP = new QLabel("RESP");
    titleRESP->setStyleSheet("background-color:rgb(25,25,25)");
    QPalette peRESP;
    peRESP.setColor(QPalette::WindowText,Qt::white);
    titleRESP->setPalette(peRESP);
    QLabel *textRESP1 = new QLabel("  -?-");
    textRESP1->setStyleSheet("font:35px");
    QPalette petextRESP1;
    petextRESP1.setColor(QPalette::WindowText,Qt::yellow);
    textRESP1->setPalette(petextRESP1);

    QLabel *textRESP2 = new QLabel("             bmp");
    textRESP2->setStyleSheet("font:15px");
    QPalette petextRESP2;
    petextRESP2.setColor(QPalette::WindowText,Qt::yellow);
    textRESP2->setPalette(petextRESP2);

    QVBoxLayout *layouttextRESP=new QVBoxLayout();
    layouttextRESP->addWidget(textRESP2);
    layouttextRESP->addWidget(textRESP1);
    layouttextRESP->setStretch(0,1);
    layouttextRESP->setStretch(1,8);

    QVBoxLayout *layoutRESP=new QVBoxLayout();
    layoutRESP->addWidget(titleRESP);
    layoutRESP->addLayout(layouttextRESP);
    layoutRESP->setStretch(0,1);
    layoutRESP->setStretch(1,5);

    //C02区
    QLabel *titleCO2 = new QLabel("CO2");
    titleCO2->setStyleSheet("background-color:rgb(25,25,25)");
    QPalette peCO2;
    peCO2.setColor(QPalette::WindowText,Qt::yellow);
    titleCO2->setPalette(peCO2);
    QLabel *textCO21 = new QLabel("   -?-");
    QLabel *textCO22 = new QLabel("ins -?-");
    QLabel *textCO23 = new QLabel("awrr -?-");
    QLabel *textCO24 = new QLabel("                mmHg");
    textCO21->setStyleSheet("font:30px");
    textCO22->setStyleSheet("font:20px");
    textCO23->setStyleSheet("font:20px");
    textCO24->setStyleSheet("font:15px");
    QPalette petextCO21;
    petextCO21.setColor(QPalette::WindowText,Qt::yellow);
    textCO21->setPalette(petextCO21);
    QPalette petextCO22;
    petextCO22.setColor(QPalette::WindowText,Qt::yellow);
    textCO22->setPalette(petextCO22);
    QPalette petextCO23;
    petextCO23.setColor(QPalette::WindowText,Qt::yellow);
    textCO23->setPalette(petextCO23);
    QPalette petextCO24;
    petextCO24.setColor(QPalette::WindowText,Qt::yellow);
    textCO24->setPalette(petextCO24);

    QHBoxLayout *layouttextCO21=new QHBoxLayout();
    layouttextCO21->addWidget(textCO22);
    layouttextCO21->addWidget(textCO23);

    QVBoxLayout *layouttextCO22=new QVBoxLayout();
    layouttextCO22->addWidget(textCO24);
    layouttextCO22->addWidget(textCO21);
    layouttextCO22->addLayout(layouttextCO21);
    layouttextCO22->setStretch(0,1);
    layouttextCO22->setStretch(1,2);
    layouttextCO22->setStretch(2,1);

    QVBoxLayout *layoutCO2=new QVBoxLayout();
    layoutCO2->addWidget(titleCO2);
    layoutCO2->addLayout(layouttextCO22);
    layoutCO2->setStretch(0,1);
    layoutCO2->setStretch(1,5);
    
    //右侧部分界面布局，用水平布局+垂直布局方式完成
    QHBoxLayout* layoutTableLine1 = new QHBoxLayout();
    layoutTableLine1->addLayout(layoutHR);
    layoutTableLine1->addLayout(layoutST);

    QHBoxLayout* layoutTableLine2 = new QHBoxLayout();
    layoutTableLine2->addLayout(layoutNIBP);

    QHBoxLayout* layoutTableLine3 = new QHBoxLayout();
    layoutTableLine3->addLayout(layoutSpO2);
    layoutTableLine3->addLayout(layoutTEMP);
    layoutTableLine3->setStretch(0,1);
    layoutTableLine3->setStretch(1,1);

    QHBoxLayout* layoutTableLine4 = new QHBoxLayout();
    layoutTableLine4->addLayout(layoutRESP);
    layoutTableLine4->addLayout(layoutCO2);
    layoutTableLine4->setStretch(0,1);
    layoutTableLine4->setStretch(1,1);

    QVBoxLayout* layoutTable = new QVBoxLayout();
    layoutTable->addLayout(layoutTableLine1);
    layoutTable->addLayout(layoutTableLine2);
    layoutTable->addLayout(layoutTableLine3);
    layoutTable->addLayout(layoutTableLine4);

    //波形区域和参数区域水平布局
    QHBoxLayout *layoutDown=new QHBoxLayout();
    layoutDown->addLayout(layoutWave);
    layoutDown->addLayout(layoutTable);
    layoutDown->setStretch(0,2);
    layoutDown->setStretch(1,1);

    //主界面布局1：10
    QVBoxLayout *layoutMain=new QVBoxLayout();
    layoutMain->addWidget(title);
    layoutMain->addLayout(layoutDown);
    layoutMain->setStretch(0,1);
    layoutMain->setStretch(1,10);

    //主界面创建
    QWidget *widgetMain=new QWidget();
    widgetMain->resize(800,480);
    widgetMain->setWindowFlags(Qt::FramelessWindowHint);//隐藏标题栏
    widgetMain->setLayout(layoutMain);

    widgetMain->setParent(&w);
    w.resize(800,480);
    w.setStyleSheet("background-color:black");
    w.show();

    return a.exec();
}
