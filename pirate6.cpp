#include "pirate6.h"

Pirate6::Pirate6(Point **path, int pathLength, Point &p):
    Pirates(path,pathLength,p)
{
    this->_id=6;
    this->_life=500;
    this->_fullLife=500;
    this->_speed=20;
    this->_fullSpeed=20;
    this->_imagePath=":/Image/pictures/pirate6.png";
    this->_reward=400;
    this->_range=160;
    this->_fireBlank=12;
    this->_countBlank=12;
    this->_rangeColor="darkred";
}

