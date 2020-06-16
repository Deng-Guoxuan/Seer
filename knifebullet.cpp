#include "knifebullet.h"

KnifeBullet::KnifeBullet(Point&startPoint, Point&targetPoint):
    Bullet(startPoint,targetPoint)
{
    this->_type=6;
    this->_speed=18;
    this->_imagePath=":/Image/pictures/knifeBullet.png";
    this->_attack=50;//攻击力
}