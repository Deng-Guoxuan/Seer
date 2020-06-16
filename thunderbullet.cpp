#include "thunderbullet.h"

ThunderBullet::ThunderBullet(Point&startPoint, Point&targetPoint):
    Bullet(startPoint,targetPoint)
{
    this->_type=12;
    this->_speed=24;
    this->_imagePath=":/Image/pictures/lightingBullet.png";
    this->_attack=70;//攻击力
}
