#include "redbullet.h"

RedBullet::RedBullet(Point &startPoint, Point &targetPoint):
    Bullet(startPoint,targetPoint)
{
    this->_type=2;
    this->_speed=24;
    this->_imagePath=":/Image/pictures/redBullet.png";
    this->_attack=30;//攻击力
}
