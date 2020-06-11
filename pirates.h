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
    Pirates(Point **path, int pathLength, Point &p, int id);
    int getSpeed()const;//取得速度
    int getX()const;//左上角x坐标
    int getY()const;//左上角y坐标
    int getLife()const;//取得血量
    void setLife(const int life);//设置血量
    QString getImagePath()const;//取得图片路径
    int getID()const;//获得海盗类型
    void pirateMove();//一个海盗移动
    int getReward()const;
    bool isEnd();//判断是不是到终点了
    int getRange()const;

    QVector<Bullet*>& getBulletVector();//返回子弹数组
    void addBullet(Point &targetP); //新建子弹
    void fireBullets();//管理该精灵所有子弹的移动
    void eraseBullet(Bullet** i);//删除第i个子弹
    void setSplashed(const bool tf);//设置是否溅伤
    bool getSplashed()const;

    int getFireBlank()const;//攻击间隔
    QString getRangeColor()const;

protected:
    int _type;//海盗种类
    int _speed;//移动速度
    int _range;//攻击范围
    int _fireBlank;//攻击间隔
    int _countBlank=0;//时刻变化调整计算间隔
    Point _p;//左上角坐标
    int _life;//血量
    QString _imagePath;//图片路径
    QVector <Point*> _turningPoints;//储存行走路径的转弯处的点
    int _id;//海盗类型
    int _reward;//金钱奖励
    QString _rangeColor;
    bool _isSplashed=false;//判断是否被溅伤,是的话画图

    QVector<Bullet*> _bulletVector;//子弹数组

};

#endif // PIRATES_H