#include "mengyiyou.h"

MengYiYou::MengYiYou(int x,int y):Spirits(x,y)
{
    this->_type=3;
    this->_range=120;
    this->_cost=100;
    this->_fireBlank=8;
    this->_countBlank=8;
    this->_imagePath=QString(":/Image/pictures/MengYiYou.png");
    this->_rangeColor="blue";
    this->_life=120;
    this->_fullLife=120;
}
