#ifndef SUNBULLET_H
#define SUNBULLET_H

//阳子弹：光子弹的升级版：无特殊效果

#include "bullet.h"

class SunBullet : public Bullet
{
public:
    SunBullet(Point&startPoint, Point&targetPoint);
};

#endif // SUNBULLET_H