#ifndef WATERBULLET_H
#define WATERBULLET_H

//水子弹：蓝子弹的升级版：更大的减速范围

#include "bullet.h"

class WaterBullet : public Bullet
{
public:
    WaterBullet(Point&startPoint, Point&targetPoint);
};

#endif // WATERBULLET_H