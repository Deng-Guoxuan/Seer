#ifndef SWORDBULLET_H
#define SWORDBULLET_H

//剑子弹：刀子弹的升级版：穿透效果

#include "bullet.h"

class SwordBullet : public Bullet
{
public:
    SwordBullet(Point&startPoint, Point&targetPoint);
};

#endif // SWORDBULLET_H