#include "skeletonbullet.h"

SkeletonBullet::SkeletonBullet(Point&startPoint, Point&targetPoint):
    Bullet(startPoint,targetPoint)
{
    this->_type=17;
    this->_speed=18;
    this->_imagePath=":/Image/pictures/skeletonBullet.png";
    this->_attack=1000;//攻击力
}
