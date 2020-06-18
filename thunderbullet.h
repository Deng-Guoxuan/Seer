#ifndef THUNDERBULLET_H
#define THUNDERBULLET_H

//雷子弹：电子弹的升级版：麻痹效果

#include "bullet.h"

class ThunderBullet : public Bullet
{
public:
    ThunderBullet(Point&startPoint, Point&targetPoint);
};

#endif // THUNDERBULLET_H