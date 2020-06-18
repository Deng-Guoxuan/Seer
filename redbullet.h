#ifndef REDBULLET_H
#define REDBULLET_H

//红子弹：范围溅伤效果

#include "bullet.h"

class RedBullet : public Bullet
{
public:
    RedBullet(Point&startPoint, Point&targetPoint);
};

#endif // REDBULLET_H