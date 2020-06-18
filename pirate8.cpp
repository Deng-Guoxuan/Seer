#include "pirate8.h"

Pirate8::Pirate8(Point **path, int pathLength, Point &p):
    Pirates(path,pathLength,p)
{
    this->_id=8;
    this->_life=2500;
    this->_fullLife=2500;
    this->_speed=16;
    this->_fullSpeed=16;
    this->_imagePath=":/Image/pictures/pirate8.png";
    this->_reward=800;
    this->_range=140;
    this->_fireBlank=30;
    this->_countBlank=30;
    this->_rangeColor="lightblue";
}
