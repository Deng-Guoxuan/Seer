#include "pirate5.h"

Pirate5::Pirate5(Point **path, int pathLength, Point &p):
    Pirates(path,pathLength,p)
{
    this->_id=5;
    this->_life=400;
    this->_fullLife=400;
    this->_speed=16;
    this->_fullSpeed=16;
    this->_imagePath=":/Image/pictures/pirate5.png";
    this->_reward=300;
    this->_range=140;
    this->_fireBlank=15;
    this->_countBlank=15;
    this->_rangeColor="black";
}
