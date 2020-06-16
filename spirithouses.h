#ifndef SPIRITHOUSES_H
#define SPIRITHOUSES_H

#include "point.h"

//记录下图中能召唤精灵的位置


class SpiritHouses
{
public:
    SpiritHouses(int x,int y);
    int getX(){return this->_p.getX();}
    int getY(){return this->_p.getY();}
    int getWidth()const{return this->_width;}
    int getHeight()const{return this->_width;}

private:
    Point _p;                    //位置（左上角的点）
    const int _width=64;               //宽=64像素
    const int _height=64;              //高=64像素
};

#endif // SPIRITHOUSES_H