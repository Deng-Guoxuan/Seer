#include "menghuohou.h"

MengHuoHou::MengHuoHou(int x, int y):Spirits(x,y)
{
    this->_type=2;
    this->_range=140;
    this->_cost=100;
    this->_fireBlank=6;
    this->_countBlank=6;
    this->_imagePath=QString(":/Image/pictures/MengHuoHou.png");
    this->_rangeColor="red";
    this->_life=100;
    this->_fullLife=100;
    this->_addLifeBlank=10;
    this->_countLifeBlank=0;//一开始不可以加血
    this->_addLife=5;//每次加5血
}
