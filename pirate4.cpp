#include "pirate4.h"

Pirate4::Pirate4(Point **path, int pathLength, Point &p):
    Pirates(path,pathLength,p)
{
    this->_id=4;
    this->_life=250;
    this->_fullLife=250;
    this->_speed=10;
    this->_fullSpeed=10;
    this->_imagePath=":/Image/pictures/pirate4.png";
    this->_reward=80;
    this->_range=150;
    this->_fireBlank=8;
    this->_countBlank=8;
    this->_rangeColor="blue";
}
