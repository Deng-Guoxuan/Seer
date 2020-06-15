#include "interface.h"
#include <QMediaPlayer>
#include "world1.h"

Interface::Interface(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(500,330);

    QMediaPlayer* loginBGM=new QMediaPlayer(this);
    loginBGM->setMedia(QUrl("qrc:/Music/sounds/loginBGM.mp3"));
    loginBGM->setVolume(30);
    loginBGM->play();

    //监听关卡按钮点击 第一关
    QPushButton* map1=new QPushButton(this);
    map1->setGeometry(30,40,195,195);
    map1->setIconSize(QSize(195,195));
    map1->setStyleSheet("border:Opx;");
    map1->setIcon(QIcon(":/Image/pictures/login1.png"));


    connect(map1, &QPushButton::clicked, [=]()
    {
        //点击按钮进入关卡
        World1 *world1 = new World1;
        loginBGM->stop();
        world1->setAttribute(Qt::WA_DeleteOnClose);//提前设置好该窗口关闭的时候释放内存
        world1->show(); //关卡显示
    });

    QPushButton* map2=new QPushButton(this);
    map2->setGeometry(275,40,195,195);
    map2->setIconSize(QSize(195,195));
    map2->setStyleSheet("border:Opx;");
    map2->setIcon(QIcon(":/Image/pictures/login2.png"));
}

void Interface::paintEvent(QPaintEvent *){
    QPainter painter(this);

    DrawLogin(painter);
}

void Interface::DrawLogin(QPainter &painter){
    painter.drawPixmap(0,0,500,330,QPixmap(":/Image/pictures/login.png"));
}