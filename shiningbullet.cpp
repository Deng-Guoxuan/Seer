#include "shiningbullet.h"

ShiningBullet::ShiningBullet(Point &startPoint, Point &targetPoint):
    Bullet(startPoint,targetPoint)
{
    this->_type=8;
    this->_speed=24;
    this->_imagePath=":/Image/pictures/shiningBullet.png";
    this->_attack=40;//攻击力
}

