#ifndef SUNBULLET_H
#define SUNBULLET_H

#include "bullet.h"

class SunBullet : public Bullet
{
public:
    SunBullet(Point&startPoint, Point&targetPoint);
};

#endif // SUNBULLET_H