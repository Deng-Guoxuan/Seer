#ifndef SPIRITS_H
#define SPIRITS_H

#include <QString>
#include "point.h"
#include "pirates.h"
#include "bullet.h"

//精灵父类

class Spirits
{
public:
    Spirits(int x,int y);//默认构造函数
    int getX()const;//左上角x坐标
    int getY()const;//左上角y坐标
    int getRange()const;//攻击范围
    QString getImagePath()const;//获得图片路径
    QString getRangeColor()const;//获得攻击范围的颜色

    Pirates* getTarget() const;//返回当前精灵的目标海盗
    void setTarget(Pirates* target);//设置当前精灵的目标怪物
    int getFireBlank()const;//攻击间隔

    QVector<Bullet*>& getBulletVector();//返回子弹数组
    void addBullet(); //新建子弹
    void fireBullets();//管理该精灵所有子弹的移动
    void eraseBullet(Bullet** i);//删除第i个子弹


protected:
    int _type;//精灵种类
    Point _p;//精灵左上角坐标
    int _range;//攻击范围
    int _cost;//价钱
    int _fireBlank;//攻击间隔
    int _countBlank=0;//一直变动,用来计算攻击间隔
    QString _imagePath;//对应图片路径
    QString _rangeColor;//攻击范围的颜色

    Pirates* _target=NULL;//精灵的目标海盗

    QVector<Bullet*> _bulletVector;  //子弹结构数组

};

#endif // SPIRITS_H