#ifndef LIGHTINGBULLET_H
#define LIGHTINGBULLET_H

//电子弹：麻痹敌人攻击和移动

#include "bullet.h"

class LightingBullet : public Bullet
{
public:
    LightingBullet(Point&startPoint, Point&targetPoint);
};

#endif // LIGHTINGBULLET_H