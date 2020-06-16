#include "bluebullet.h"

BlueBullet::BlueBullet(Point&startPoint, Point&targetPoint):
    Bullet(startPoint,targetPoint)
{
    this->_type=3;
    this->_speed=24;
    this->_imagePath=":/Image/pictures/blueBullet.png";
    this->_attack=20;//攻击力
}
