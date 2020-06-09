#include "mengbubuzhongzi.h"

MengBuBuZhongZi::MengBuBuZhongZi(int x, int y):Spirits(x,y)
{
    this->_type=1;
    this->_range=120;
    this->_cost=100;
    this->_fireBlank=10;
    this->_imagePath=QString(":/Image/pictures/MengBuBuZhongZi.png");
    this->_rangeColor="green";
}


