#ifndef FIREBULLET_H
#define FIREBULLET_H

//火子弹：范围溅伤效果
#include "bullet.h"

class FireBullet : public Bullet
{
public:
    FireBullet(Point&startPoint,Point&targetPoint);
};

#endif // FIREBULLET_H