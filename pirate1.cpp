#include "pirate1.h"

Pirate1::Pirate1(Point **path, int pathLength, Point &p):
    Pirates(path,pathLength,p)
{
    this->_id=1;
    this->_life=100;
    this->_fullLife=100;
    this->_speed=6;
    this->_fullSpeed=6;
    this->_imagePath=":/Image/pictures/pirate1.png";
    this->_reward=20;
    this->_range=100;
    this->_fireBlank=15;
    this->_countBlank=15;
    this->_rangeColor="black";
}
