#include "capsule.h"

Capsule::Capsule(int x, int y):_p(x,y){}

int Capsule::getX()const{
    return this->_p.getX();
}

int Capsule::getY()const{
    return this->_p.getY();
}

int Capsule::getWidth()const{
    return this->_width;
}

int Capsule::getHeight()const{
    return this->_width;
}

int Capsule::getOccupied()const{
    return this->_occupied;
}

void Capsule::setOccupied(const int num){
    this->_occupied=num;
}
