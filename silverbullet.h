#ifndef SILVERBULLET_H
#define SILVERBULLET_H

//银子弹：高伤害

#include "bullet.h"

class SilverBullet : public Bullet
{
public:
    SilverBullet(Point&startPoint, Point&targetPoint);
};

#endif // SILVERBULLET_H