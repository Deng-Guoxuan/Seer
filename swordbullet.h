#ifndef SWORDBULLET_H
#define SWORDBULLET_H

#include "bullet.h"

class SwordBullet : public Bullet
{
public:
    SwordBullet(Point&startPoint, Point&targetPoint);
};

#endif // SWORDBULLET_H