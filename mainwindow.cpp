#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include "interface.h"
#include <QMediaPlayer>
#include <QPainter>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(1068,600);
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/Image/pictures/base.png"));

    QMediaPlayer* startBGM=new QMediaPlayer(this);
    startBGM->setMedia(QUrl("qrc:/Music/sounds/startBGM.mp3"));
    startBGM->setVolume(30);
    startBGM->play();

    this->_seer=new QLabel(this);
    this->_seer->setGeometry(220,100,625,300);
    this->_seer->setFont(QFont("微软雅黑",150,75));//字体，大小，粗细
    this->_seer->setStyleSheet("color:yellow");//背景颜色，字体颜色
    this->_seer->setAlignment(Qt::AlignCenter);//居中
    this->_seer->setText(QString("Seer"));

    this->_maker=new QLabel(this);
    this->_maker->setGeometry(300,400,468,100);
    this->_maker->setFont(QFont("微软雅黑",20,20));//字体，大小，粗细
    this->_maker->setStyleSheet("color:yellow");//背景颜色，字体颜色
    this->_maker->setAlignment(Qt::AlignCenter);//居中
    this->_maker->setText(QString("制作人：RUC邓国翾"));

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

    //精灵图鉴
    QPushButton* handbook=new QPushButton(this);
    handbook->setGeometry(950,300,57,57);
    handbook->setIconSize(QSize(57,57));
    handbook->setStyleSheet("border:Opx;");
    handbook->setIcon(QIcon(":/Image/pictures/handbook.png"));
    connect(handbook, &QPushButton::clicked, [=]()
    {
        this->_displayHandbook ? this->_displayHandbook = false : this->_displayHandbook = true;
        update();
    });



}

MainWindow::~MainWindow()
{
    delete this->_seer;
    delete this->_maker;
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);

    DrawInterface(painter);
    DrawHandbook(painter);
}

void MainWindow::DrawInterface(QPainter &painter){
    painter.drawPixmap(0,0,1068,600,QPixmap(":/Image/pictures/startform.png"));
    painter.drawPixmap(750,440,250,158,QPixmap(":/Image/pictures/logo.png"));
}

void MainWindow::DrawHandbook(QPainter &painter){
    if(this->_displayHandbook){
        this->_seer->hide();
        this->_maker->hide();
        painter.setPen(QColor("grey"));
        painter.setBrush(QBrush(QColor("grey"),Qt::Dense2Pattern));//填充颜色，透明度
        painter.drawRect(180,60,700,375);
        painter.setBrush(Qt::NoBrush);
        painter.setPen(Qt::NoPen);
        painter.drawPixmap(180,60,350,375,QPixmap(":/Image/pictures/spirits.png"));
        painter.drawPixmap(530,60,320,217,QPixmap(":/Image/pictures/pirates.png"));
    }
    else{
        this->_seer->show();
        this->_maker->show();
    }
}
