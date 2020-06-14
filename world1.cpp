#include "world1.h"

#include "ui_mainwindow.h"
#include "capsule.h"    //精灵房子位置
#include "mengbubuzhongzi.h" //萌布布种子
#include "windows.h"
#include "menghuohou.h"
#include "mengyiyou.h"

const int PIX=64;//一格64像素

World1::World1(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(1152,640);//设置窗口大小
    setWindowTitle("Seer");//设置窗口名称

    this->_moneyLabel->setGeometry(10*PIX,0.75*PIX,3*PIX,PIX/2);//位置
    this->_moneyLabel->setFont(QFont("微软雅黑",12,75));//字体，大小，粗细
    this->_moneyLabel->setStyleSheet("background-color:whitesmoke;color:goldenrod");//背景颜色，字体颜色
    this->_moneyLabel->setAlignment(Qt::AlignCenter);//居中
    this->_moneyLabel->setText(QString("Money:%1").arg(this->_money));

    this->_lifeLabel->setGeometry(10*PIX,0.25*PIX,3*PIX,PIX/2);
    this->_lifeLabel->setFont(QFont("微软雅黑",12,75));
    this->_lifeLabel->setStyleSheet("background-color:white;color:firebrick");
    this->_lifeLabel->setAlignment(Qt::AlignCenter);
    this->_lifeLabel->setText(QString("Life:%1").arg(this->_life));

    this->_winLabel->setGeometry(4*PIX,3*PIX,10*PIX,4*PIX);
    this->_winLabel->setFont(QFont("微软雅黑",108,75));//字体，大小，粗细
    this->_winLabel->setStyleSheet("color:orange");//背景颜色，字体颜色
    this->_winLabel->setAlignment(Qt::AlignCenter);//居中
    this->_winLabel->setText(QString("You win!"));
    this->_winLabel->hide();

    this->_loseLabel->setGeometry(4*PIX,3*PIX,10*PIX,4*PIX);
    this->_loseLabel->setFont(QFont("微软雅黑",108,75));//字体，大小，粗细
    this->_loseLabel->setStyleSheet("color:grey");//背景颜色，字体颜色
    this->_loseLabel->setAlignment(Qt::AlignCenter);//居中
    this->_loseLabel->setText(QString("You lose!"));
    this->_loseLabel->hide();//隐藏

    QMediaPlayer * player = new QMediaPlayer(this);//指明父类是本页面,则该页面析构的时候指针可以跟着析构
    player->setMedia(QUrl("qrc:/Music/sounds/BGM.mp3"));//背景音乐
    player->setVolume(30);
    player->play();

    QTimer* timer1 = new QTimer(this);      //用于插入海盗定时器
    timer1->start(this->getPirateBlank());      //插入海盗的间隔时间
    connect(timer1,&QTimer::timeout,[=](){                          //设置路径点
        Point* path1[]={new Point(6*PIX,6*PIX),new Point(8*PIX,6*PIX),new Point(8*PIX,5*PIX),new Point(13*PIX,5*PIX),
                        new Point(13*PIX,6*PIX),new Point(14*PIX,6*PIX),new Point(14*PIX,7*PIX),new Point(10*PIX,7*PIX),
                        new Point(10*PIX,8*PIX),new Point(7*PIX,8*PIX),new Point(7*PIX,9*PIX),new Point(5*PIX,9*PIX),
                        new Point(5*PIX,7*PIX),new Point(4*PIX,7*PIX),new Point(4*PIX,8*PIX),new Point(3*PIX,8*PIX),
                        new Point(3*PIX,7*PIX),new Point(2*PIX,7*PIX),new Point(2*PIX,6*PIX),new Point(1*PIX,6*PIX),
                        new Point(1*PIX,4*PIX),new Point(2*PIX,4*PIX),new Point(2*PIX,3*PIX),new Point(3*PIX,3*PIX),
                        new Point(this->_base)
                       };//最后的路径点设为家
        Point entrance[]={Point(6*PIX, 5*PIX)};//入口位置
        int pathLengths[]={sizeof(path1)/sizeof(Point*)};//路径的结点个数
        setPiratesWave(path1, entrance, pathLengths);   //使用预设的1条路产生怪物方案
        timer1->setInterval(this->getPirateBlank());//修改海盗出现时间间隔
    });

    //
    QTimer* timer2=new QTimer(this);
    timer2->start(150);
    connect(timer2,&QTimer::timeout,[=](){
        if(this->_theEnd){          //结束标记
            Sleep(5000);
            this->close();
        }
        this->allPiratesMove();//界面所有海盗移动
        this->allSpiritsFindTarget();//界面所有精灵找目标

        this->bingoPirateEvent();//击中海盗事件

        this->allPirateFindTarget();//界面所有海盗找目标

        this->bingoSpiritEvent();//击中精灵事件
        update();//画图
    });

    QTimer* timer3=new QTimer(this);
    timer3->start(50);
    connect(timer3,&QTimer::timeout,[=](){
        for(auto spirit:this->_spiritsVector){//界面所有精灵子弹移动
            spirit->fireBullets();
        }
        for(auto pirate:this->_pirateVector){//界面所有海盗子弹移动
            pirate->fireBullets();
        }
    });

    QTimer* timer4=new QTimer(this);
    timer4->start(1000);//1秒刷新一次
    connect(timer4,&QTimer::timeout,[=](){
        this->addLifeEvent();
    });

    //一键显示所有精灵攻击范围按钮
    QPushButton* displayAllSpiritRangePush = new QPushButton(this);
    displayAllSpiritRangePush->setStyleSheet("color:black");
    displayAllSpiritRangePush->setGeometry(10*PIX,1.25*PIX, 3*PIX, PIX/2);//位置
    displayAllSpiritRangePush->setFont(QFont("宋体", 12,75));//字体，大小，粗细
    displayAllSpiritRangePush->setText("精灵攻击范围");

    connect(displayAllSpiritRangePush,&QPushButton::clicked,[=]()
    {
        this->_displayAllSpiritRange ? this->_displayAllSpiritRange = false : this->_displayAllSpiritRange = true;  //通过改变标识令防御塔攻击范围显示或关闭
        update();
    });

    //一键显示所有海盗攻击范围按钮
    QPushButton* displayAllPirateRangePush = new QPushButton(this);
    displayAllPirateRangePush->setStyleSheet("color:black");
    displayAllPirateRangePush->setGeometry(10*PIX,1.75*PIX, 3*PIX, PIX/2);//位置
    displayAllPirateRangePush->setFont(QFont("宋体", 12,75));//字体，大小，粗细
    displayAllPirateRangePush->setText("海盗攻击范围");

    connect(displayAllPirateRangePush,&QPushButton::clicked,[=]()
    {
        this->_displayAllPirateRange ? this->_displayAllPirateRange = false : this->_displayAllPirateRange = true;  //通过改变标识令防御塔攻击范围显示或关闭
        update();
    });

    //一键显示所有海盗血量按钮
    QPushButton* displayAllPirateLifePush = new QPushButton(this);
    displayAllPirateLifePush->setStyleSheet("color:darkred");
    displayAllPirateLifePush->setGeometry(13*PIX,1.75*PIX, 2*PIX, PIX/2);//位置
    displayAllPirateLifePush->setFont(QFont("宋体", 12,75));//字体，大小，粗细
    displayAllPirateLifePush->setText("海盗血量");

    connect(displayAllPirateLifePush,&QPushButton::clicked,[=]()
    {
        this->_displayPirateLifeBar ? this->_displayPirateLifeBar = false : this->_displayPirateLifeBar = true;  //通过改变标识令防御塔攻击范围显示或关闭
        update();
    });

    //一键显示所有精灵血量按钮
    QPushButton* displayAllSpiritLifePush = new QPushButton(this);
    displayAllSpiritLifePush->setStyleSheet("color:darkred");
    displayAllSpiritLifePush->setGeometry(13*PIX,1.25*PIX, 2*PIX, PIX/2);//位置
    displayAllSpiritLifePush->setFont(QFont("宋体", 12,75));//字体，大小，粗细
    displayAllSpiritLifePush->setText("精灵血量");

    connect(displayAllSpiritLifePush,&QPushButton::clicked,[=]()
    {
        this->_displaySpiritLifeBar ? this->_displaySpiritLifeBar = false : this->_displaySpiritLifeBar = true;  //通过改变标识令防御塔攻击范围显示或关闭
        update();
    });

}


//补血事件
void World1::addLifeEvent(){
    this->_countLifeBlank++;
    if(this->_countLifeBlank<this->_addLifeBlank){  //未达到时间间隔
        return;
    }
    else{
        for(auto spirit:this->_spiritsVector){
            if(spirit->getType()==1){            //是萌布布种子
                for(auto spirit2:this->_spiritsVector){
                    Point p1(spirit->getX()+PIX/2,spirit->getY()+PIX/2);
                    Point p2(spirit2->getX()+PIX/2,spirit2->getY()+PIX/2);
                    if(getLength(p1,p2)<spirit->getRange()){                     //在范围内
                        if(spirit2->getLife()+this->_addLife > spirit2->getFullLife()){
                            spirit2->setLife(spirit2->getFullLife());                       //加血只能加到上限
                        }
                        else{
                            spirit2->setLife(spirit2->getLife()+this->_addLife);//加血
                        }
                    }
                    else continue;
                }
            }
            else continue;
        }
        this->_countLifeBlank=0;//归零
    }
}

//击中精灵事件
void World1::bingoSpiritEvent(){
    for(auto pirate:this->_pirateVector){                 //遍历海盗
        for(auto bullet=pirate->getBulletVector().begin();bullet<pirate->getBulletVector().end();bullet++){        //遍历该精灵的子弹
            for(auto spirit=this->_spiritsVector.begin();spirit<this->_spiritsVector.end();spirit++){          //遍历精灵
                Point p1((*bullet)->getX(),(*bullet)->getY());   //子弹中心
                Point p2((*spirit)->getX()+PIX/2,(*spirit)->getY()+PIX/2);   //精灵中心
                if(this->isBingo(p1,p2)){                    //击中
                    (*spirit)->setLife((*spirit)->getLife()-(*bullet)->getAttack());//扣血
                    pirate->eraseBullet(bullet);                  //删去子弹

                    if((*spirit)->getLife()<=0){        //精灵没血了
                        Point p1((*spirit)->getX(),(*spirit)->getY());
                        this->setCapsuleOccupied(p1,0);                  //解除精灵胶囊的占用
                        this->_spiritsVector.erase(spirit);               //删除精灵
                    }
                    else{}
                    break;
                }
                else continue;
            }
        }
    }
}




//击中海盗事件
void World1::bingoPirateEvent(){
    for(auto splash=this->_splashedPointVector.begin();splash<this->_splashedPointVector.end();splash++){
        this->_splashedPointVector.erase(splash);//先清空溅伤点
    }
    for(auto wave=this->_wavedPointVector.begin();wave<this->_wavedPointVector.end();wave++){
        this->_wavedPointVector.erase(wave);
    }//清空海浪点
    for(auto spirit:this->_spiritsVector){                 //遍历精灵
        for(auto bullet=spirit->getBulletVector().begin();bullet<spirit->getBulletVector().end();bullet++){        //遍历该精灵的子弹
            for(auto pirate=this->_pirateVector.begin();pirate<this->_pirateVector.end();pirate++){          //遍历海盗
                Point p1((*bullet)->getX(),(*bullet)->getY());   //子弹中心
                Point p2((*pirate)->getX()+PIX/2,(*pirate)->getY()+PIX/2);   //海盗中心
                if(this->isBingo(p1,p2)){                    //击中
                    switch ((*bullet)->getType()) {               //根据子弹类型触发不同效果
                    case 1://绿子弹：无其他效果,碰到目标即消失
                    {
                        (*pirate)->setLife((*pirate)->getLife()-(*bullet)->getAttack());//扣血
                        spirit->eraseBullet(bullet);
                        break;
                    }
                    case 2://红子弹：范围溅伤效果,碰到目标即消失
                    {
                        redBulletEffect(p1,(*bullet)->getAttack());
                        (*pirate)->setLife((*pirate)->getLife()-(*bullet)->getAttack());//扣血
                        spirit->eraseBullet(bullet);
                        break;
                    }
                    case 3://蓝子弹：范围减速效果,碰到目标即消失
                    {
                        blueBulletEffect(p1,0.5);
                        (*pirate)->setLife((*pirate)->getLife()-(*bullet)->getAttack());//扣血
                        spirit->eraseBullet(bullet);
                        break;
                    }
                    default:
                        break;
                    }

                    if((*pirate)->getLife()<=0){        //海盗没血了
                        //判断一下其他精灵的目标怪物是否和当前精灵消灭的怪物重复，如果重复，则将那一个防御塔的目标怪物也设为空
                        for (auto spirit2 : this->_spiritsVector){
                            if (spirit2->getTarget() == *pirate){
                                spirit2->setTarget(NULL);
                            }
                        }
                        this->_money += (*pirate)->getReward();//击败怪物增加金钱
                        this->_moneyLabel->setText(QString("金钱：%1").arg(this->_money));//刷新标签
                        this->_pirateVector.erase(pirate);               //删除怪物
                    }
                    else{}
                    break;
                }
                else continue;
            }
        }
    }
}

//界面所有海盗找目标
void World1::allPirateFindTarget(){
    //海盗寻找目标精灵的规律：找到最近的一个精灵作为目标
    for (auto pirate : this->_pirateVector){       //遍历海盗
        for(auto spirit: this->_spiritsVector){    //遍历精灵
            //先判断在不在攻击范围内
            Point p1(spirit->getX()+PIX/2,spirit->getY()+PIX/2);//精灵中心点
            Point p2(pirate->getX()+PIX/2,pirate->getY()+PIX/2);//海盗中心点
            if(this->inRange(getLength(p1,p2),pirate->getRange())){                 //如果在攻击范围内了
                pirate->addBullet(p1);//增加一个子弹
            }
            else continue;
        }
    }
}


//界面所有精灵找目标
void World1::allSpiritsFindTarget(){
    //精灵寻找目标海盗的规律：找到最前一个海盗作为目标，目标丢失后找再继续找下一个目标
    for (auto spirit : this->_spiritsVector){       //遍历精灵
        if(!spirit->getTarget()){                   //若当前没有目标海盗
            for(int i = 0; i <=this->_pirateVector.size() - 1; i++){                 //遍历海盗
                //这里以精灵中心点和怪物中心点判断
                Point p1(spirit->getX()+PIX/2,spirit->getY()+PIX/2);
                Point p2(this->_pirateVector.at(i)->getX()+PIX/2,this->_pirateVector.at(i)->getY()+PIX/2);
                if (this->inRange(getLength(p1,p2),spirit->getRange())){             //如果在攻击范围内
                    spirit->setTarget(this->_pirateVector.at(i));                    //设置精灵的目标怪物
                    break;                                                           //找到后立刻跳出循环
                }
                else{}
            }
        }
        else{                 //当前已经有了目标海盗
            //先判断在不在攻击范围内
            Point p1(spirit->getX()+PIX/2,spirit->getY()+PIX/2);//精灵中心点
            Point p2(spirit->getTarget()->getX()+PIX/2,spirit->getTarget()->getY()+PIX/2);//海盗中心点
            if(!this->inRange(getLength(p1,p2),spirit->getRange())){                 //如果不在攻击范围内了
                spirit->setTarget(NULL); //目标置为空
            }
            else{               //目标在攻击范围内
                spirit->addBullet();//一直增加子弹
            }
        }
    }
}

//界面所有海盗的移动
void World1::allPiratesMove(){
    for (auto pirate = this->_pirateVector.begin(); pirate != this->_pirateVector.end(); pirate++){
        if((*pirate)->isEnd()){                   //海盗走到终点

            //判断一下所有精灵的目标海盗是否和当前删除的海盗重复，如果重复，则将那一个精灵的目标海盗也设为空
            for (auto spirit : this->_spiritsVector){
                if (spirit->getTarget() == *pirate){
                    spirit->setTarget(NULL);
                }
            }
            delete *pirate;
            this->_pirateVector.erase(pirate);         //海盗走到终点则删除这个海盗

            this->_life--;//减生命
            this->_lifeLabel->setText(QString("Life:%1").arg(this->_life));//刷新生命标签

            if(this->_life<=0){
                this->_loseLabel->show();
                this->_theEnd=true;
            }
            else{}
            break;
        }
        else{
            (*pirate)->pirateMove();//海盗移动
        }
    }
}

//萌火猴的红子弹范围溅伤效果：传入当前命中目标的中心点,以及该子弹的攻击力(溅伤四分之一的攻击力)
void World1::redBulletEffect(Point &p,int damage){
    for(auto pirate:this->_pirateVector){        //遍历海盗
        Point p2(pirate->getX()+PIX/2,pirate->getY()+PIX/2);//海盗中心点
        if(getLength(p,p2)<=80 && getLength(p,p2)>0){      //80范围内的海盗被溅伤
            this->_splashedPointVector.push_back(new Point(p2));//加入一个要画出溅伤的点
            pirate->setLife(pirate->getLife()-damage/4);   //溅伤扣血
        }
    }
}

//萌伊尤的蓝子弹的范围减速效果：传入当前命中目标的中心点,以及减速的到满速的比例
void World1::blueBulletEffect(Point &p, double percentage){
    for(auto pirate:this->_pirateVector){
        Point p2(pirate->getX()+PIX/2,pirate->getY()+PIX/2);
        if(getLength(p,p2)<=100){                      //100范围内海盗减速
            this->_wavedPointVector.push_back(new Point(p2));//加入一个要画海浪的点
            pirate->setSpeed(pirate->getFullSpeed()*percentage);//设置新的速度
            pirate->setWaved(true);//减速标记
        }
    }
}

//析构释放内存
World1::~World1()
{
    //释放海盗数组
    for (auto it = this->_pirateVector.begin(); it != this->_pirateVector.end(); it++){
        delete *it;
        *it=NULL;
    }

    //释放精灵屋指针数组
    for (auto it = this->_capsuleVector.begin(); it != this->_capsuleVector.end(); it++){
        delete *it;
        *it=NULL;
    }

    //释放选择框类
    delete this->_bag;
    this->_bag=NULL;

    //释放精灵数组
    for(auto it = this->_spiritsVector.begin(); it != this->_spiritsVector.end(); it++){
        delete *it;
        *it=NULL;
    }

    //释放溅伤点数组
    for(auto it = this->_splashedPointVector.begin(); it != this->_splashedPointVector.end(); it++){
        delete *it;
        *it=NULL;
    }

    for(auto it = this->_wavedPointVector.begin();it != this->_wavedPointVector.end();it++){
        delete *it;
        *it=NULL;
    }
}

//绘图事件
void World1::paintEvent(QPaintEvent *){
    QPainter painter(this);//画家类

    DrawMap1(painter);//画出地图
    DrawPirate(painter);//画出海盗
    DrawSpirits(painter);//画出精灵
    DrawSelectionBox(painter);//画选择框
    DrawAddLife(painter);//加血特效
    DrawWave(painter);//减速特效
    DrawSplash(painter);//溅伤特效
    DrawSpiritLifeBar(painter);//精灵血条
    DrawPirateLifeBar(painter);//海盗血条

}

void World1::DrawSpiritLifeBar(QPainter &painter){
    if(this->_displaySpiritLifeBar){
        for(auto spirit:this->_spiritsVector){
            int lifeLength=spirit->getLife()*(PIX-8)/spirit->getFullLife();//剩余血量
            painter.drawPixmap(spirit->getX()+4,spirit->getY()-PIX/4,lifeLength,PIX/8,QPixmap(":/Image/pictures/redBar.png"));
            painter.drawPixmap(spirit->getX()+lifeLength,spirit->getY()-PIX/4,PIX-8-lifeLength,PIX/8,QPixmap(":/Image/pictures/whiteBar.png"));
            painter.setPen(QPen(Qt::yellow, 1, Qt::SolidLine));//设置画笔，黄色，实线
            painter.drawRect(QRect(spirit->getX()+4,spirit->getY()-PIX/4,PIX-8,PIX/8));//将选中区域用黄色实线框起来
        }
    }
    else return;
}

void World1::DrawPirateLifeBar(QPainter &painter){
    if(this->_displayPirateLifeBar){
        for(auto pirate:this->_pirateVector){
            int lifeLength=pirate->getLife()*(PIX-8)/pirate->getFullLife();//剩余血量
            painter.drawPixmap(pirate->getX()+4,pirate->getY()-PIX/4,lifeLength,PIX/8,QPixmap(":/Image/pictures/redBar.png"));
            painter.drawPixmap(pirate->getX()+lifeLength,pirate->getY()-PIX/4,PIX-8-lifeLength,PIX/8,QPixmap(":/Image/pictures/whiteBar.png"));
            painter.setPen(QPen(Qt::yellow, 1, Qt::SolidLine));//设置画笔，黄色，实线
            painter.drawRect(QRect(pirate->getX()+4,pirate->getY()-PIX/4,PIX-8,PIX/8));//将选中区域用黄色实线框起来
        }
    }
    else return;
}

void World1::DrawSplash(QPainter &painter){
    for(auto point:this->_splashedPointVector){
        painter.drawPixmap(point->getX()-PIX/2,point->getY()+PIX/4,PIX,PIX/4,QPixmap(":/Image/pictures/splashed.png"));
    }
}

void World1::DrawWave(QPainter &painter){
    for(auto point:this->_wavedPointVector){
        painter.drawPixmap(point->getX()-PIX/2,point->getY()+2,PIX,30,QPixmap(":/Image/pictures/wave.png"));
    }
}

void World1::DrawAddLife(QPainter &painter){
    if(this->_countLifeBlank >= this->_addLifeBlank-1){
        for(auto spirit:this->_spiritsVector){
            if(spirit->getType()==1){
                painter.setPen(QColor("lightgreen"));
                painter.setBrush(QBrush(QColor("lightgreen"),Qt::Dense7Pattern));//填充颜色，透明度
                painter.drawEllipse(QPoint(spirit->getX()+PIX/2, spirit->getY()+PIX/2), spirit->getRange(), spirit->getRange());
            }
        }
    }
}

//画出地图，包括：精灵屋位置、基地位置
void World1::DrawMap1(QPainter &painter){
    painter.drawPixmap(0,0,1152,640,QPixmap(":/Image/pictures/Map1.png"));//地图
    painter.drawPixmap(3*PIX,2*PIX,64,64,QPixmap(":/Image/pictures/base.png"));//基地

    Point capsules[]={Point(0*PIX,3*PIX),Point(0*PIX,6*PIX),
                      Point(1*PIX,2*PIX),Point(1*PIX,7*PIX),
                      Point(2*PIX,2*PIX),Point(2*PIX,5*PIX),Point(2*PIX,8*PIX),
                      Point(3*PIX,4*PIX),Point(3*PIX,6*PIX),Point(3*PIX,9*PIX),
                      Point(4*PIX,2*PIX),Point(4*PIX,3*PIX),Point(4*PIX,6*PIX),Point(4*PIX,9*PIX),
                      Point(5*PIX,5*PIX),Point(5*PIX,6*PIX),
                      Point(6*PIX,7*PIX),Point(6*PIX,8*PIX),
                      Point(7*PIX,5*PIX),Point(7*PIX,7*PIX),
                      Point(8*PIX,4*PIX),Point(8*PIX,7*PIX),Point(8*PIX,9*PIX),
                      Point(9*PIX,4*PIX),Point(9*PIX,6*PIX),Point(9*PIX,7*PIX),Point(9*PIX,9*PIX),
                      Point(10*PIX,4*PIX),Point(10*PIX,6*PIX),Point(10*PIX,9*PIX),
                      Point(11*PIX,4*PIX),Point(11*PIX,6*PIX),Point(11*PIX,8*PIX),Point(11*PIX,9*PIX),
                      Point(12*PIX,4*PIX),Point(12*PIX,6*PIX),Point(12*PIX,8*PIX),
                      Point(13*PIX,4*PIX),Point(13*PIX,8*PIX),
                      Point(14*PIX,5*PIX),Point(14*PIX,8*PIX),
                      Point(15*PIX,5*PIX),Point(15*PIX,6*PIX),Point(15*PIX,7*PIX),Point(15*PIX,8*PIX)
                      };    //精灵屋位置
    int sumHouses=sizeof(capsules)/sizeof(Point(1,1));
    for(int i=0;i<sumHouses;i++){
        painter.drawPixmap(capsules[i].getX(),capsules[i].getY(),PIX,PIX,QPixmap(":Image/pictures/Capsule.png"));//画出精灵屋
        this->_capsuleVector.push_back(new Capsule(capsules[i].getX(),capsules[i].getY()));//并记录下这些精灵屋的位置到Vector中
    }

}

void World1::addPirate(int pirateType, Point **path, int pathLength,Point& startPoint){
    this->_pirateVector.push_back(new Pirates(path,pathLength,startPoint,pirateType));
}

void World1::setPiratesWave(Point **path1, Point *entrance, int*pathLengths){
    Point** ways[]{path1};//储存不同的线路
    //加入海盗
    if(this->_count >= 1 && this->_count <= 10){
        addPirate(1,ways[0],pathLengths[0],entrance[0]); //海盗类型，路径，路径长度，起始点
    }
    else if(this->_count>=10 && this->_count<=14){
        this->setPirateBlank(1000);
        addPirate(2,ways[0],pathLengths[0],entrance[0]);
    }
    else if(this->_count>=15 && this->_count<=30){
        this->setPirateBlank(2000);
        addPirate(1,ways[0],pathLengths[0],entrance[0]);
        addPirate(2,ways[0],pathLengths[0],entrance[0]);

    }
    else if(this->_count>=31){
        if(this->_pirateVector.empty()){                 //海盗出完了,且海盗打完了
            this->_winLabel->show();
            this->_theEnd=true;
        }
    }
    this->_count++;          //计数器+1
    update();
}

//画海盗及其子弹
void World1::DrawPirate(QPainter &painter){
    for(auto pirate: this->_pirateVector){//遍历海盗数组

        if(this->_displayAllPirateRange){ //要显示所有海盗攻击范围
            painter.setPen(QColor(pirate->getRangeColor()));//根据海盗的不同绘制不同颜色的攻击范围框
            painter.setBrush(QBrush(QColor(pirate->getRangeColor()),Qt::Dense5Pattern));//填充颜色，透明度
            painter.drawEllipse(QPoint(pirate->getX()+PIX/2, pirate->getY()+PIX/2), pirate->getRange(), pirate->getRange());
        }


        painter.drawPixmap(pirate->getX(),pirate->getY(),PIX,PIX,QPixmap(pirate->getImagePath()));
        //画出子弹
        for(auto bullet:pirate->getBulletVector()){
            painter.drawPixmap(bullet->getX()-PIX/4,bullet->getY()-PIX/4,PIX/2,PIX/2,QPixmap(bullet->getImagePath()));
        }
    }
}

//画精灵及其子弹
void World1::DrawSpirits(QPainter &painter){
    for (auto spirit : this->_spiritsVector)  //遍历精灵数组
    {
        if(this->_displayAllSpiritRange){ //要显示所有精灵攻击范围
            painter.setPen(QColor(spirit->getRangeColor()));//根据精灵的不同绘制不同颜色的攻击范围框
            painter.setBrush(QBrush(QColor(spirit->getRangeColor()),Qt::Dense5Pattern));//填充颜色，透明度
            painter.drawEllipse(QPoint(spirit->getX()+PIX/2, spirit->getY()+PIX/2), spirit->getRange(), spirit->getRange());
        }

        //画出精灵
        painter.drawPixmap(spirit->getX(),spirit->getY(),PIX,PIX,QPixmap(spirit->getImagePath()));
        painter.resetTransform();   //重置调整

        //画出子弹
        for(auto bullet:spirit->getBulletVector()){
            painter.drawPixmap(bullet->getX()-PIX/4,bullet->getY()-PIX/4,PIX/2,PIX/2,QPixmap(bullet->getImagePath()));
        }
    }
}


void World1::DrawSelectionBox(QPainter &painter){
    //显示选择框
    if (!this->_bag->getDisplay()){
        return;
    }
    else{
        //画出选择框
         painter.drawPixmap(this->_bag->getX(),this->_bag->getY(),2*PIX,3*PIX,QPixmap(this->_bag->getImgPath()));

         //画出子按钮
         SubButton* copySubButtons = this->_bag->getSubButtons();//接收子按钮结构数组
         for(int i=0;i<6;i++){
             painter.drawPixmap(copySubButtons[i].getX(),copySubButtons[i].getY(),PIX,PIX,QPixmap(copySubButtons[i].getImagePath()));
         }

         painter.setPen(QPen(Qt::yellow, 6, Qt::SolidLine));//设置画笔，黄色，实线
         painter.drawRect(QRect(this->_bag->getX()-PIX,this->_bag->getY()+2*PIX,PIX,PIX));//将选中区域用黄色实线框起来
    }
}

//将鼠标点击转化为格子点击
bool World1::clickThisBlock(int mouseX, int mouseY, int blockX, int blockY){
    if(mouseX>=blockX && mouseX<=(blockX+PIX) && mouseY>=blockY &&mouseY<=(blockY+PIX)){
        return true;
    }
    else return false;
}

void World1::setCapsuleOccupied(const Point &p, const int k){
    for(auto capsule:this->_capsuleVector){
        Point p2(capsule->getX(),capsule->getY());
        if(getLength(p,p2)==0){
            capsule->setOccupied(k);
        }
        else continue;
    }
}

//鼠标点击事件
void World1::mousePressEvent(QMouseEvent *ev){
    if(ev->button()!=Qt::LeftButton){
        return;                          //如果不是鼠标左键点击，则不做反应
    }
    else{
        //判断选择框6个子按钮的点击
        SubButton* clickSubButton=this->_bag->getSubButtons();
        for(int i=0;i<6;i++){
            //如果点到了背包中的该精灵的位置，且该背包此时是显示出来的情况下
            if((clickThisBlock(ev->x(),ev->y(),clickSubButton[i].getX(),clickSubButton[i].getY())) && (this->_bag->getDisplay())){
                this->_bag->setDisplay(false);//准备关掉背包

                //根据i的选择加入新的精灵到Vector中
                switch (i) {
                case 0://萌布布种子
                {
                    if(this->canBuy(100)){    //够钱
                        this->_spiritsVector.push_back(new MengBuBuZhongZi(this->_bag->getX()-PIX,this->_bag->getY()+2*PIX));
                        Point p1(this->_bag->getX()-PIX,this->_bag->getY()+2*PIX);
                        this->setCapsuleOccupied(p1,1);
                    }
                    break;
                }
                case 1://萌火猴
                {
                    if(this->canBuy(100)){    //够钱
                        this->_spiritsVector.push_back(new MengHuoHou(this->_bag->getX()-PIX,this->_bag->getY()+2*PIX));
                        Point p1(this->_bag->getX()-PIX,this->_bag->getY()+2*PIX);
                        this->setCapsuleOccupied(p1,2);
                    }
                    break;
                }
                case 2://萌伊尤
                {
                    if(this->canBuy(100)){    //够钱
                        this->_spiritsVector.push_back(new MengYiYou(this->_bag->getX()-PIX,this->_bag->getY()+2*PIX));
                        Point p1(this->_bag->getX()-PIX,this->_bag->getY()+2*PIX);
                        this->setCapsuleOccupied(p1,3);
                    }
                    break;
                }
                default:break;
                }
                update();//更新
                return;
            }
            else continue;
        }

        //判断塔坑的点击
        for(auto capsule:this->_capsuleVector){        //遍历所有塔坑
            //判断点击塔坑
            if(clickThisBlock(ev->x(),ev->y(),capsule->getX(),capsule->getY())){  //选到了一个塔坑
                switch (capsule->getOccupied()) {
                case 0:               //该位置为空
                {
                    this->_bag->clickOne(capsule->getX(),capsule->getY());                  //设置选择框位置并显示出来
                    break;
                }
                default:break;
                }
                update();//更新
                return;
            }
            else continue;
        }
        this->_bag->setDisplay(false);//关闭选择框
        update();//更新
    }
}

bool World1::canBuy(int cost){
    if(cost<=this->_money){
        this->_money = this->_money-cost;//扣钱
        this->_moneyLabel->setText(QString("Money:%1").arg(this->_money));//刷新
        return true;//能买
    }
    else return false;
}

bool World1::inRange(int distance, int range){
    if(distance<=range){
        return true;
    }
    else return false;
}

bool World1::isBingo(Point &bulletP, Point &targetP){
    if(getLength(bulletP,targetP)<1*PIX){
        return true;
    }
    else return false;
}

void World1::setPirateBlank(const int blank){
    this->_pirateBlank=blank;
}

int World1::getPirateBlank()const{
    return this->_pirateBlank;
}
