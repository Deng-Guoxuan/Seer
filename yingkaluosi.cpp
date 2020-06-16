#include "yingkaluosi.h"

YingKaLuoSi::YingKaLuoSi(int x,int y):Spirits(x,y)
{
    this->_type=5;
    this->_range=160;
    this->_cost=700;
    this->_fireBlank=6;
    this->_countBlank=6;
    this->_imagePath=QString(":/Image/pictures/YingKaLuoSi.png");
    this->_rangeColor="darkred";
    this->_life=200;
    this->_fullLife=200;
    this->_addLifeBlank=6;
    this->_countLifeBlank=0;//一开始不可以加血
    this->_addLife=10;//每次加10血
}
