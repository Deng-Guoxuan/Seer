#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include "interface.h"
#include <QMediaPlayer>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(1068,600);
    ui->setupUi(this);

    QMediaPlayer* startBGM=new QMediaPlayer(this);
    startBGM->setMedia(QUrl("qrc:/Music/sounds/startBGM.mp3"));
    startBGM->setVolume(30);
    startBGM->play();

    QPushButton *start=new QPushButton(this);
    start->setGeometry(400,500,268,60);
    start->setText("Start");
    start->setStyleSheet("background-color:ivory");
    start->setStyleSheet("color:red");
    start->setIconSize(QSize(100,50));
    start->setFont(QFont("华文行楷",24,75));
    connect(start, &QPushButton::clicked, [=]()
    {
        //点击按钮进入关卡
        Interface *interface = new Interface;
        startBGM->stop();
        interface->setAttribute(Qt::WA_DeleteOnClose);//提前设置好该窗口关闭的时候释放内存
        interface->show(); //关卡显示
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);

    DrawInterface(painter);
}

void MainWindow::DrawInterface(QPainter &painter){
    painter.drawPixmap(0,0,1068,600,QPixmap(":/Image/pictures/startform.png"));
    painter.drawPixmap(750,440,250,158,QPixmap(":/Image/pictures/logo.png"));
}
