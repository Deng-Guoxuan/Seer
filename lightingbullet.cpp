#include "lightingbullet.h"

LightingBullet::LightingBullet(Point&startPoint, Point&targetPoint):
    Bullet(startPoint,targetPoint)
{
    this->_type=4;
    this->_speed=24;
    this->_imagePath=":/Image/pictures/lightingBullet.png";
    this->_attack=40;//攻击力
}
