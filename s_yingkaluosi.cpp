#include "s_yingkaluosi.h"

S_YingKaLuoSi::S_YingKaLuoSi(int x,int y):Spirits(x,y)
{
    this->_type=11;
    this->_range=200;
    this->_cost=900;
    this->_fireBlank=6;
    this->_countBlank=6;
    this->_imagePath=QString(":/Image/pictures/S_YingKaLuoSi.png");
    this->_rangeColor="darkred";
    this->_life=280;
    this->_fullLife=280;
    this->_addLifeBlank=4;
    this->_countLifeBlank=0;//一开始不可以加血
    this->_addLife=20;//每次加20血
}
