#include "pirate2.h"

Pirate2::Pirate2(Point **path, int pathLength, Point &p):
    Pirates(path,pathLength,p)
{
    this->_id=2;
    this->_life=120;
    this->_fullLife=120;
    this->_speed=12;
    this->_fullSpeed=12;
    this->_imagePath=":/Image/pictures/pirate2.png";
    this->_reward=60;
    this->_range=100;
    this->_fireBlank=10;
    this->_countBlank=10;
    this->_rangeColor="black";
}
