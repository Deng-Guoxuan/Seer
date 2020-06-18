#ifndef SKELETONBULLET_H
#define SKELETONBULLET_H

//骷髅子弹：没有精灵能够抵挡一次攻击

#include "bullet.h"

class SkeletonBullet : public Bullet
{
public:
    SkeletonBullet(Point&startPoint, Point&targetPoint);
};

#endif // SKELETONBULLET_H