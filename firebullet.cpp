#include "firebullet.h"

FireBullet::FireBullet(Point &startPoint, Point &targetPoint):
    Bullet(startPoint,targetPoint)
{
    this->_type=10;
    this->_speed=24;
    this->_imagePath=":/Image/pictures/fireBullet.png";
    this->_attack=80;//攻击力
}
