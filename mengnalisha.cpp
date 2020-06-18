#include "mengnalisha.h"

const int PIX=64;

MengNaLiSha::MengNaLiSha(int x, int y):Spirits(x,y)
{
    this->_type=7;
    this->_range=130;
    this->_cost=200;
    this->_fireBlank=8;
    this->_countBlank=8;
    this->_imagePath=QString(":/Image/pictures/MengNaLiSha.png");
    this->_rangeColor="green";
    this->_life=600;
    this->_fullLife=600;
    this->_addLifeBlank=2;
    this->_countLifeBlank=2;//一开始就可以加血
    this->_addLife=200;//每次加200血
}
