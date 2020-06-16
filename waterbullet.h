#ifndef WATERBULLET_H
#define WATERBULLET_H

#include "bullet.h"

class WaterBullet : public Bullet
{
public:
    WaterBullet(Point&startPoint, Point&targetPoint);
};

#endif // WATERBULLET_H