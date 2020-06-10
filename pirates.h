#ifndef PIRATES_H
#define PIRATES_H

#include <QString>
#include <QVector>
#include "point.h"


//海盗父类

class Pirates
{
public:
    Pirates(Point **path, int pathLength, Point &p, int id);
    int getSpeed()const;//取得速度
    int getX()const;//左上角x坐标
    int getY()const;//左上角y坐标
    int getLife()const;//取得血量
    void setLife(int life);//设置血量
    QString getImagePath()const;//取得图片路径
    int getID()const;//获得海盗类型
    bool pirateMove();//海盗移动
    int getReward()const;
    bool isEnd();//判断是不是到终点了

protected:
    int _speed;//移动速度
    Point _p;//左上角坐标
    int _life;//血量
    QString _imagePath;//图片路径
    QVector <Point*> _turningPoints;//储存行走路径的转弯处的点
    int _id;//海盗类型
    int _reward;//金钱奖励

};

#endif // PIRATES_H