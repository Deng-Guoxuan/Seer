#ifndef LIGHTINGBULLET_H
#define LIGHTINGBULLET_H

#include "bullet.h"

class LightingBullet : public Bullet
{
public:
    LightingBullet(Point&startPoint, Point&targetPoint);
};

#endif // LIGHTINGBULLET_H