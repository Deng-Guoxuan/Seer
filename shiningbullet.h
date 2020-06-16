#ifndef SHININGBULLET_H
#define SHININGBULLET_H

#include "bullet.h"

class ShiningBullet : public Bullet
{
public:
    ShiningBullet(Point&startPoint, Point&targetPoint);
};

#endif // SHININGBULLET_H