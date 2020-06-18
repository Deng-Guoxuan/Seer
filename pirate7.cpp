#include "pirate7.h"

Pirate7::Pirate7(Point **path, int pathLength, Point &p):
    Pirates(path,pathLength,p)
{
    this->_id=7;
    this->_life=1500;
    this->_fullLife=1500;
    this->_speed=10;
    this->_fullSpeed=10;
    this->_imagePath=":/Image/pictures/pirate7.png";
    this->_reward=450;
    this->_range=180;
    this->_fireBlank=20;
    this->_countBlank=20;
    this->_rangeColor="darkgreen";
}
