#ifndef KNIFEBULLET_H
#define KNIFEBULLET_H

#include "bullet.h"

class KnifeBullet : public Bullet
{
public:
    KnifeBullet(Point&startPoint, Point&targetPoint);
};

#endif // KNIFEBULLET_H