#ifndef GREENBULLET_H
#define GREENBULLET_H

//绿子弹：无特效
#include "bullet.h"

class GreenBullet : public Bullet
{
public:
    GreenBullet(Point&startPoint, Point&targetPoint);
};

#endif // GREENBULLET_H