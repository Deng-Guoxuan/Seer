#ifndef PIRATES_H
#define PIRATES_H

#include <QString>
#include <QVector>
#include "point.h"
#include "bullet.h"



//海盗父类

class Pirates
{
public:
    Pirates(Point **path, int pathLength, Point &p);
    int getSpeed()const;//取得速度
    int getX()const;//左上角x坐标
    int getY()const;//左上角y坐标
    int getLife()const;//取得血量
    int getID()const;//获得海盗类型
    int getReward()const;
    int getFireBlank()const;//攻击间隔
    int getRange()const;
    int getFullLife()const;
    int getFullSpeed()const;

    void setLife(const int life);//设置血量
    void pirateMove();//一个海盗移动
    void addBullet(Point &targetP); //新建子弹
    void fireBullets();//管理该精灵所有子弹的移动
    void eraseBullet(Bullet** bullet);//删除第i个子弹
    void setSplashed(const bool tf);//设置是否溅伤
    void setSpeed(const int speed);//设置速度
    void setWaved(const bool tf);
    void setCountBlank(const int t);//专为雷伊技能增加的函数,改变攻击间隔的计算
    void setShocked(const bool tf);

    bool isEnd();//判断是不是到终点了
    bool getSplashed()const;
    bool getWaved()const;
    bool getShocked()const;


    QString getImagePath()const;//取得图片路径
    QString getRangeColor()const;//攻击范围的颜色

    QVector<Bullet*>& getBulletVector();//返回子弹数组

protected:
    int _id;//海盗种类
    int _speed;//移动速度(会变)
    int _fullSpeed;//满速
    int _norSpdBlank=50;
    int _range;//攻击范围
    int _fireBlank;//攻击间隔
    int _countBlank=0;//时刻变化调整计算攻击间隔
    int _life;//血量
    int _fullLife;//血量上限
    int _reward;//金钱奖励

    bool _isSplashed=false;//判断是否被溅伤,是的话画图
    bool _isWaved=false;//判断是否被减速
    bool _shocked=false;//判断是否被麻痹

    Point _p;//左上角坐标

    QString _imagePath;//图片路径
    QString _rangeColor;

    QVector <Point*> _turningPoints;//储存行走路径的转弯处的点
    QVector<Bullet*> _bulletVector;//子弹数组

};

#endif // PIRATES_H