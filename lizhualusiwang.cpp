#include "lizhualusiwang.h"


LiZhuaLuSiWang::LiZhuaLuSiWang(int x, int y):Spirits(x,y)
{
    this->_type=9;
    this->_range=140;
    this->_cost=200;
    this->_fireBlank=7;
    this->_countBlank=7;
    this->_imagePath=QString(":/Image/pictures/LiZhuaLuSiWang.png");
    this->_rangeColor="blue";
    this->_life=200;
    this->_fullLife=200;
    this->_addLifeBlank=8;
    this->_countLifeBlank=0;//一开始不可以加血
    this->_addLife=10;//每次加10血
}
