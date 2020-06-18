#ifndef FLOWERBULLET_H
#define FLOWERBULLET_H

//花子弹：无特效
#include "bullet.h"

class FlowerBullet : public Bullet
{
public:
    FlowerBullet(Point&startPoint, Point&targetPoint);
};

#endif // FLOWERBULLET_H