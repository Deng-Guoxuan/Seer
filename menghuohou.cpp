#include "menghuohou.h"

MengHuoHou::MengHuoHou(int x, int y):Spirits(x,y)
{
    this->_type=2;
    this->_range=150;
    this->_cost=100;
    this->_fireBlank=6;
    this->_imagePath=QString(":/Image/pictures/MengHuoHou.png");
    this->_rangeColor="red";
}
