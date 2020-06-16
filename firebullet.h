#ifndef FIREBULLET_H
#define FIREBULLET_H

#include "bullet.h"

class FireBullet : public Bullet
{
public:
    FireBullet(Point&startPoint,Point&targetPoint);
};

#endif // FIREBULLET_H