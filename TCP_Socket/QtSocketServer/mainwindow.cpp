#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pixmap = new QPixmap(this->width(), this->height());
    pixmap->fill(Qt::black);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    drawWidget();
}

void MainWindow::drawWidget()
{
    QPainter *painter = new QPainter();
    // 启动绘图
    painter->begin(this);
    // 把缓冲区内容画到界面上
    painter->drawPixmap(0, 0, *pixmap);
    // 绘图结束
    painter->end();
}

