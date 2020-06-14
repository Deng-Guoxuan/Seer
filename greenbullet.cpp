#include "greenbullet.h"

GreenBullet::GreenBullet(Point &startPoint, Point &targetPoint):
    Bullet(startPoint,targetPoint)
{
    this->_type=1;
    this->_speed=24;
    this->_imagePath=":/Image/pictures/greenBullet.png";
    this->_attack=20;//攻击力
}
