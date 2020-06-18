#ifndef IRONBULLET_H
#define IRONBULLET_H

//铁子弹：高攻击

#include "bullet.h"

class IronBullet : public Bullet
{
public:
    IronBullet(Point&startPoint,Point&targetPoint);
};

#endif // IRONBULLET_H