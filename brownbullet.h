#ifndef BROWNBULLET_H
#define BROWNBULLET_H

//棕子弹：编号7：高伤害
#include "bullet.h"

class BrownBullet : public Bullet
{
public:
    BrownBullet(Point&startPoint,Point&targetPoint);
};

#endif // BROWNBULLET_H