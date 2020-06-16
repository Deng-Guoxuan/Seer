#include "swordbullet.h"

SwordBullet::SwordBullet(Point&startPoint, Point&targetPoint):
    Bullet(startPoint,targetPoint)
{
    this->_type=13;
    this->_speed=18;
    this->_imagePath=":/Image/pictures/swordBullet.png";
    this->_attack=80;//攻击力
}
