#include "blackbullet.h"

BlackBullet::BlackBullet(Point &startPoint, Point &targetPoint):
    Bullet(startPoint,targetPoint)
{
    this->_type=4;
    this->_speed=24;
    this->_imagePath=":Image/pictures/blackBullet.png";
    this->_attack=10;//攻击力
}
