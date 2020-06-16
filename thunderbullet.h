#ifndef THUNDERBULLET_H
#define THUNDERBULLET_H

#include "bullet.h"

class ThunderBullet : public Bullet
{
public:
    ThunderBullet(Point&startPoint, Point&targetPoint);
};

#endif // THUNDERBULLET_H