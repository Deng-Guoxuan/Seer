#ifndef BLUEBULLET_H
#define BLUEBULLET_H

#include "bullet.h"

class BlueBullet : public Bullet
{
public:
    BlueBullet(Point&startPoint,Point&targetPoint);
};

#endif // BLUEBULLET_H