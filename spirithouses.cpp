#include "spirithouses.h"

SpiritHouses::SpiritHouses(int x, int y):_p(x,y){}

int SpiritHouses::getX()const{
    return this->_p.getX();
}

int SpiritHouses::getY()const{
    return this->_p.getY();
}

int SpiritHouses::getWidth()const{
    return this->_width;
}

int SpiritHouses::getHeight()const{
    return this->_width;
}
