#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>                //画家
#include <Qtimer>                  //定时器
#include <QMediaPlayer>
#include <QMouseEvent>             //鼠标事件
#include <QLabel>                  //标签
#include "capsule.h"
#include "pirates.h"
#include "spirits.h"
#include "selectionbox.h"
#include "point.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent *);//绘图事件
    bool clickThisBlock(int mouseX,int mouseY,int blockX,int blockY);//判断鼠标点击位置是否在当前方格内，是返回true


private:
    Ui::MainWindow *ui;

    int _count=0;//计算海盗的数量，决定出现新的海盗以及游戏结束
    int _money=200;//初始钱数
    int _life=10;//生命值
    const Point _base=Point(192,128);//基地位置，敌人进入即游戏结束（可以设置最大进入人数）
    bool _displayAllRange=false;//一键显示所有精灵攻击范围
    QVector <Capsule*> _capsuleVector;//精灵屋类数组
    QVector <Pirates*> _pirateVector;//海盗类数组
    QVector <Spirits*> _spiritsVector;//精灵类数组
    SelectionBox* _bag=new SelectionBox(":/Image/pictures/bag.png"); //选择框类
    QLabel* _moneyLabel=new QLabel(this);//刷新金钱标签
    QLabel* _lifeLabel=new QLabel(this);//刷新生命值标签
    bool _theEnd=false;//结束标记
    QLabel* _winLabel=new QLabel(this);//胜利标签
    QLabel* _loseLabel=new QLabel(this);//失败标签
    int _pirateBlank=3000;//插入海盗的间隔时间,根据海盗难度调整

    void DrawMap1(QPainter& painter);//画出地图Map1
    void setPiratesWave(Point **path1, Point *entrance, int* pathLengths);//设置每波海盗的形式
    void DrawPirate(QPainter& painter);//画出海盗
    void DrawSpirits(QPainter& painter);//画出精灵
    void DrawSelectionBox(QPainter& painter);//画出选择框
    void mousePressEvent(QMouseEvent* ev);//鼠标点击事件
    void addPirate(int pirateType, Point** path, int pathLength, Point &startPoint);//增加一个海盗
    bool canBuy(int cost);//判断是否能购买，能即true
    bool inRange(int distance,int range);//判断海盗是否进入攻击范围
    bool bingo(Point&bulletP,Point&pirateP);//判断子弹是否击中海盗
    void setCapsuleOccupied(const Point&p,const int k);//标记已有精灵的胶囊
    int getPirateBlank()const;
    void setPirateBlank(const int blank);

};



#endif // MAINWINDOW_H
