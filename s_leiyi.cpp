#include "s_leiyi.h"

S_LeiYi::S_LeiYi(int x, int y):Spirits(x,y)
{
    this->_type=10;
    this->_range=200;
    this->_cost=700;
    this->_fireBlank=6;
    this->_countBlank=6;
    this->_imagePath=QString(":/Image/pictures/S_LeiYi.png");
    this->_rangeColor="yellow";
    this->_life=400;
    this->_fullLife=400;
    this->_addLifeBlank=4;
    this->_countLifeBlank=0;//一开始不可以加血
    this->_addLife=20;//每次加20血
}
