#include "puni.h"

PuNi::PuNi(int x, int y):Spirits(x,y)
{
    this->_type=6;
    this->_range=28;//谱尼没有攻击范围,向周围发射子弹
    this->_cost=1000;
    this->_fireBlank=30;
    this->_countBlank=30;
    this->_imagePath=QString(":/Image/pictures/PuNi.png");
    this->_rangeColor="gold";
    this->_life=300;
    this->_fullLife=300;
    this->_addLifeBlank=5;
    this->_countLifeBlank=5;//一开始可以加血
    this->_addLife=40;//每次加40血
}

