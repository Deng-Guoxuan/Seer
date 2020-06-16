#ifndef SPIRITS_H
#define SPIRITS_H

//精灵编号：1萌布布种子,2萌火猴,3萌伊尤,4雷伊,5英卡洛斯,6谱尼
//        7蒙娜丽莎,8炽焰金刚,9利爪鲁斯王,10S_雷伊,11S_英卡洛斯,12S_谱尼

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
    int getLife()const;
    int getFullLife()const;
    int getFireBlank()const;//攻击间隔
    int getCountFireBlank()const;//计算攻击间隔
    int getType()const;
    int getAddLifeBlank()const;
    int getCountLifeBlank()const;

    void setTarget(Pirates* target);//设置当前精灵的目标怪物
    void addBullet(); //新建子弹
    void fireBullets();//管理该精灵所有子弹的移动
    void eraseBullet(Bullet** bullet);//删除第i个子弹
    void setLife(const int life);
    void addLife(QVector<Spirits *> &spiritsVector);//管理该精灵的补血事件
    void setCountFireBlank(const int num);

    QString getImagePath()const;//获得图片路径
    QString getRangeColor()const;//获得攻击范围的颜色

    Pirates* getTarget() const;//返回当前精灵的目标海盗

    QVector<Bullet*>& getBulletVector();//返回子弹数组

protected:
    int _type;//精灵种类
    int _range;//攻击范围
    int _cost;//价钱
    int _fireBlank;//攻击间隔
    int _countBlank=0;//一直变动,用来计算攻击间隔
    int _life;//生命
    int _fullLife;//生命上限
    int _addLifeBlank;//每只精灵的补血间隔
    int _countLifeBlank;//计算补血间隔
    int _addLife;//每次加多少血

    Point _p;//精灵左上角坐标

    QString _imagePath;//对应图片路径
    QString _rangeColor;//攻击范围的颜色

    Pirates* _target=NULL;//精灵的目标海盗

    QVector<Bullet*> _bulletVector;  //子弹结构数组

};

#endif // SPIRITS_H