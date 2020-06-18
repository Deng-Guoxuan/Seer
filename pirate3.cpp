#include "pirate3.h"

Pirate3::Pirate3(Point **path, int pathLength, Point &p):
    Pirates(path,pathLength,p)
{
    this->_id=3;
    this->_life=200;
    this->_fullLife=200;
    this->_speed=6;
    this->_fullSpeed=6;
    this->_imagePath=":/Image/pictures/pirate3.png";
    this->_reward=200;
    this->_range=140;
    this->_fireBlank=15;
    this->_countBlank=15;
    this->_rangeColor="brown";
}
