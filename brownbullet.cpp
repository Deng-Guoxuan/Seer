#include "brownbullet.h"

BrownBullet::BrownBullet(Point &startPoint, Point &targetPoint):
    Bullet(startPoint,targetPoint)
{
    this->_type=7;
    this->_speed=24;
    this->_imagePath=":/Image/pictures/brownBullet.png";
    this->_attack=80;//攻击力
}
