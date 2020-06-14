#ifndef REDBULLET_H
#define REDBULLET_H

#include "bullet.h"

class RedBullet : public Bullet
{
public:
    RedBullet(Point&startPoint, Point&targetPoint);
};

#endif // REDBULLET_H