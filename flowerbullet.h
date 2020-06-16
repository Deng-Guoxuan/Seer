#ifndef FLOWERBULLET_H
#define FLOWERBULLET_H

#include "bullet.h"

class FlowerBullet : public Bullet
{
public:
    FlowerBullet(Point&startPoint, Point&targetPoint);
};

#endif // FLOWERBULLET_H