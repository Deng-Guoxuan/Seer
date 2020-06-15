#include "brownbullet.h"

BrownBullet::BrownBullet(Point &startPoint, Point &targetPoint):
    Bullet(startPoint,targetPoint)
{
    this->_type=4;
    this->_speed=24;
    this->_imagePath=":/Image/pictures/brownBullet.png";
    this->_attack=60;//攻击力
}
