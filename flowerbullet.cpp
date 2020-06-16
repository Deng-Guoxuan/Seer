#include "flowerbullet.h"

FlowerBullet::FlowerBullet(Point &startPoint, Point &targetPoint):
    Bullet(startPoint,targetPoint)
{
    this->_type=9;
    this->_speed=24;
    this->_imagePath=":/Image/pictures/flowerBullet.png";
    this->_attack=40;//攻击力
}
