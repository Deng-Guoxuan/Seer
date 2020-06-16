#include "s_puni.h"

S_PuNi::S_PuNi(int x, int y):Spirits(x,y)
{
    this->_type=12;
    this->_range=28;//谱尼没有攻击范围,向周围发射子弹
    this->_cost=2000;
    this->_fireBlank=20;
    this->_countBlank=20;
    this->_imagePath=QString(":/Image/pictures/S_PuNi.png");
    this->_rangeColor="gold";
    this->_life=500;
    this->_fullLife=500;
    this->_addLifeBlank=4;
    this->_countLifeBlank=4;//一开始可以加血
    this->_addLife=80;//每次加80血
}
