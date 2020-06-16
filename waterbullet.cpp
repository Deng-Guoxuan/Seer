#include "waterbullet.h"

WaterBullet::WaterBullet(Point&startPoint, Point&targetPoint):
    Bullet(startPoint,targetPoint)
{
    this->_type=11;
    this->_speed=24;
    this->_imagePath=":/Image/pictures/waterBullet.png";
    this->_attack=40;//攻击力
}

