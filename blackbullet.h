#ifndef BLACKBULLET_H
#define BLACKBULLET_H

#include "bullet.h"

class BlackBullet : public Bullet
{
public:
    BlackBullet(Point&startPoint, Point&targetPoint);
};

#endif // BLACKBULLET_H