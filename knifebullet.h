#ifndef KNIFEBULLET_H
#define KNIFEBULLET_H

//刀子弹：穿透效果

#include "bullet.h"

class KnifeBullet : public Bullet
{
public:
    KnifeBullet(Point&startPoint, Point&targetPoint);
};

#endif // KNIFEBULLET_H