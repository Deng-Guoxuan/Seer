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
    this->_life=150;
    this->_fullLife=150;
    this->_addLifeBlank=10;
    this->_countLifeBlank=0;//一开始不可以加血
    this->_addLife=5;//每次加5血
}
