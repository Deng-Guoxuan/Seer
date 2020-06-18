#include "ironbullet.h"

IronBullet::IronBullet(Point&startPoint, Point&targetPoint):
    Bullet(startPoint,targetPoint)
{
    this->_type=15;
    this->_speed=16;
    this->_imagePath=":/Image/pictures/ironBullet.png";
    this->_attack=60;//攻击力
}