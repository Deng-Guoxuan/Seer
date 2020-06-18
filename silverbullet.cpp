#include "silverbullet.h"

SilverBullet::SilverBullet(Point&startPoint, Point&targetPoint):
    Bullet(startPoint,targetPoint)
{
    this->_type=16;
    this->_speed=24;
    this->_imagePath=":/Image/pictures/silverBullet.png";
    this->_attack=80;//攻击力
}
