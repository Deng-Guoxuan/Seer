#include "leiyi.h"

LeiYi::LeiYi(int x, int y):Spirits(x,y)
{
    this->_type=4;
    this->_range=160;
    this->_cost=500;
    this->_fireBlank=8;
    this->_countBlank=8;
    this->_imagePath=QString(":/Image/pictures/LeiYi.png");
    this->_rangeColor="yellow";
    this->_life=320;
    this->_fullLife=320;
    this->_addLifeBlank=8;
    this->_countLifeBlank=0;//一开始不可以加血
    this->_addLife=10;//每次加10血
}