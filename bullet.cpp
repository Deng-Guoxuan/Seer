#include "bullet.h"

const int PIX=64;

Bullet::Bullet(Point&startPoint, Point &targetPoint):
    _nowPosition(startPoint.getX(),startPoint.getY()),
    _direction(targetPoint.getX()-startPoint.getX(),targetPoint.getY()-startPoint.getY())
{
    this->_l=getLength(startPoint,targetPoint);//方向向量的模长
}

int Bullet::getX()const{
    return this->_nowPosition.getX();
}

int Bullet::getY()const{
    return this->_nowPosition.getY();
}

QString Bullet::getImagePath()const{
    return this->_imagePath;
}

void Bullet::setX(const int x){
    this->_nowPosition.setX(x);
}

void Bullet::setY(const int y){
    this->_nowPosition.setY(y);
}

int Bullet::getType()const{
    return this->_type;
}
void Bullet::setType(const int type)
{
    this->_type=type;
}

int Bullet::getSpeed()const{
    return this->_speed;
}

int Bullet::getL()const{
    return this->_l;
}

int Bullet::getAttack()const{
    return this->_attack;
}

void Bullet::bulletMove(){
    this->setX(this->getX()+this->_direction.getX()*this->getSpeed()/this->getL());
    this->setY(this->getY()+this->_direction.getY()*this->getSpeed()/this->getL());
}