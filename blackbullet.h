#ifndef BLACKBULLET_H
#define BLACKBULLET_H

//黑子弹：编号4：无特效
#include "bullet.h"

class BlackBullet : public Bullet
{
public:
    BlackBullet(Point&startPoint, Point&targetPoint);
};

#endif // BLACKBULLET_H