#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "capsule.h"    //精灵房子位置
#include "mengbubuzhongzi.h" //萌布布种子
#include <QPushButton>       //按键
#include "windows.h"
#include "menghuohou.h"
#include "mengyiyou.h"

const int PIX=64;//一格64像素

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

    QMediaPlayer * player = new QMediaPlayer;
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
    timer2->start(120);
    connect(timer2,&QTimer::timeout,[=](){
        //海盗移动
        if(this->_theEnd){
            Sleep(5000);
            this->close();
        }

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

        //子弹移动
        for(auto spirit:this->_spiritsVector){
            spirit->fireBullets();
        }

        //判断击中
        for(auto spirit:this->_spiritsVector){                 //遍历精灵
            for(auto bullet=spirit->getBulletVector().begin();bullet<spirit->getBulletVector().end();bullet++){        //遍历该精灵的子弹
                for(auto pirate=this->_pirateVector.begin();pirate<this->_pirateVector.end();pirate++){          //遍历海盗
                    Point p1((*bullet)->getX(),(*bullet)->getY());   //子弹中心
                    Point p2((*pirate)->getX(),(*pirate)->getY());   //海盗中心
                    if(this->bingo(p1,p2)){                    //击中
                        (*pirate)->setLife((*pirate)->getLife()-(*bullet)->getAttack());//扣血
                        spirit->eraseBullet(bullet);                  //删去子弹

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
        update();//画图
    });

    //一键显示所有精灵攻击范围按钮
    QPushButton* displayAllRangePush = new QPushButton(this);
    displayAllRangePush->setStyleSheet("color:black");
    displayAllRangePush->setGeometry(10*PIX,1.25*PIX, 3*PIX, PIX/2);//位置
    displayAllRangePush->setFont(QFont("宋体", 12,75));//字体，大小，粗细
    displayAllRangePush->setText("显示全部攻击范围");

    connect(displayAllRangePush,&QPushButton::clicked,[=]()
    {
        this->_displayAllRange ? this->_displayAllRange = false : this->_displayAllRange = true;  //通过改变标识令防御塔攻击范围显示或关闭
        update();
    });


}

//析构释放内存
MainWindow::~MainWindow()
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

    //释放海盗数组
    for(auto it = this->_pirateVector.begin(); it != this->_pirateVector.end(); it++){
        delete *it;
        *it=NULL;
    }

    delete ui;
}

//绘图事件
void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);//画家类

    DrawMap1(painter);//画出地图
    DrawPirate(painter);//画出海盗
    DrawSpirits(painter);//画出精灵
    DrawSelectionBox(painter);//画选择框
}

//画出地图，包括：精灵屋位置、基地位置
void MainWindow::DrawMap1(QPainter &painter){
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

void MainWindow::addPirate(int pirateType, Point **path, int pathLength,Point& startPoint){
    this->_pirateVector.push_back(new Pirates(path,pathLength,startPoint,pirateType));
}

void MainWindow::setPiratesWave(Point **path1, Point *entrance, int*pathLengths){
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

void MainWindow::DrawPirate(QPainter &painter){
    for(auto pirate: this->_pirateVector){
        painter.drawPixmap(pirate->getX(),pirate->getY(),PIX,PIX,QPixmap(pirate->getImagePath()));
    }
}

void MainWindow::DrawSpirits(QPainter &painter){
    for (auto spirit : this->_spiritsVector)  //遍历精灵数组
    {
        if(this->_displayAllRange){ //要显示所有精灵攻击范围
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


void MainWindow::DrawSelectionBox(QPainter &painter){
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

bool MainWindow::clickThisBlock(int mouseX, int mouseY, int blockX, int blockY){
    if(mouseX>=blockX && mouseX<=(blockX+PIX) && mouseY>=blockY &&mouseY<=(blockY+PIX)){
        return true;
    }
    else return false;
}

void MainWindow::setCapsuleOccupied(const Point &p, const int k){
    for(auto capsule:this->_capsuleVector){
        Point p2(capsule->getX(),capsule->getY());
        if(getLength(p,p2)==0){
            capsule->setOccupied(k);
        }
        else continue;
    }
}


void MainWindow::mousePressEvent(QMouseEvent *ev){
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
                    if(this->canBuy(100)==true){    //够钱
                        this->_spiritsVector.push_back(new MengBuBuZhongZi(this->_bag->getX()-PIX,this->_bag->getY()+2*PIX));
                        Point p1(this->_bag->getX()-PIX,this->_bag->getY()+2*PIX);
                        this->setCapsuleOccupied(p1,1);
                    }

                    break;
                }
                case 1://萌火猴
                {
                    if(this->canBuy(100)==true){    //够钱
                        this->_spiritsVector.push_back(new MengHuoHou(this->_bag->getX()-PIX,this->_bag->getY()+2*PIX));
                        Point p1(this->_bag->getX()-PIX,this->_bag->getY()+2*PIX);
                        this->setCapsuleOccupied(p1,2);
                    }
                    break;
                }
                case 2://萌伊尤
                {
                    if(this->canBuy(100)==true){    //够钱
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
        //遍历所有塔坑
        for(auto capsule:this->_capsuleVector){
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

bool MainWindow::canBuy(int cost){
    if(cost<=this->_money){
        this->_money = this->_money-cost;//扣钱
        this->_moneyLabel->setText(QString("Money:%1").arg(this->_money));//刷新
        return true;//能买
    }
    else return false;
}

bool MainWindow::inRange(int distance, int range){
    if(distance<=range){
        return true;
    }
    else return false;
}

bool MainWindow::bingo(Point &bulletP, Point &pirateP){
    if(getLength(bulletP,pirateP)<1*PIX){
        return true;
    }
    else return false;
}

void MainWindow::setPirateBlank(const int blank){
    this->_pirateBlank=blank;
}

int MainWindow::getPirateBlank()const{
    return this->_pirateBlank;
}

