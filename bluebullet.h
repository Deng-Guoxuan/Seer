#ifndef BLUEBULLET_H
#define BLUEBULLET_H

//蓝子弹：编号3：海盗减速30%
#include "bullet.h"

class BlueBullet : public Bullet
{
public:
    BlueBullet(Point&startPoint,Point&targetPoint);
};

#endif // BLUEBULLET_H