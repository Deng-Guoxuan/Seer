#ifndef SHININGBULLET_H
#define SHININGBULLET_H

//光子弹：无特殊效果

#include "bullet.h"

class ShiningBullet : public Bullet
{
public:
    ShiningBullet(Point&startPoint, Point&targetPoint);
};

#endif // SHININGBULLET_H