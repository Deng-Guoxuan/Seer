#include "mengbubuzhongzi.h"

const int PIX=64;

MengBuBuZhongZi::MengBuBuZhongZi(int x, int y):Spirits(x,y)
{
    this->_type=1;
    this->_range=120;
    this->_cost=100;
    this->_fireBlank=10;
    this->_countBlank=10;
    this->_imagePath=QString(":/Image/pictures/MengBuBuZhongZi.png");
    this->_rangeColor="green";
    this->_life=150;
    this->_fullLife=150;
    this->_addLifeBlank=3;
    this->_countLifeBlank=3;//一开始就可以加血
    this->_addLife=40;//每次加40血
}



