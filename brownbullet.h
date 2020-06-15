#ifndef BROWNBULLET_H
#define BROWNBULLET_H

#include "bullet.h"

class BrownBullet : public Bullet
{
public:
    BrownBullet(Point&startPoint,Point&targetPoint);
};

#endif // BROWNBULLET_H