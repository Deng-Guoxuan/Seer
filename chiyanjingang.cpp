#include "chiyanjingang.h"

ChiYanJinGang::ChiYanJinGang(int x, int y):Spirits(x,y)
{
    this->_type=8;
    this->_range=160;
    this->_cost=200;
    this->_fireBlank=4;
    this->_countBlank=4;
    this->_imagePath=QString(":/Image/pictures/ChiYanJinGang.png");
    this->_rangeColor="red";
    this->_life=350;
    this->_fullLife=350;
    this->_addLifeBlank=8;
    this->_countLifeBlank=0;//一开始不可以加血
    this->_addLife=10;//每次加10血
}
