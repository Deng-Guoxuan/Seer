#include "sunbullet.h"

SunBullet::SunBullet(Point &startPoint, Point &targetPoint):
    Bullet(startPoint,targetPoint)
{
    this->_type=14;
    this->_speed=24;
    this->_imagePath=":/Image/pictures/sunBullet.png";
    this->_attack=60;//攻击力
}
