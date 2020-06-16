#ifndef BULLET_H
#define BULLET_H

//子弹编号：1绿,2红,3蓝,4黑,5电,6刀,7棕,8光,9花,10火,11水,12雷,13剑,14阳

#include "point.h"
#include <QString>

//子弹

class Bullet
{
public:
    Bullet(Point&startPoint,Point&targetPoint);
    int getX()const;
    int getY()const;
    int getSpeed()const;
    int getType()const;
    int getL()const;//方向向量的模长
    int getAttack()const;

    void setX(const int x);
    void setY(const int y);
    void bulletMove();//子弹移动
    void setType(const int type);

    QString getImagePath()const;

protected:
    int _type;//子弹类型
    int _speed;//子弹速度
    int _l;//方向向量的模长
    int _attack;//攻击力(与对应精灵一致)
    Point _nowPosition;//当前中心坐标
    Point _direction;//这是一个方向向量(未单位化),记录子弹运动方向
    QString _imagePath;//子弹图片路径
};

#endif // BULLET_H