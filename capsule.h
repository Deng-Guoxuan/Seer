#ifndef SPIRITHOUSES_H
#define SPIRITHOUSES_H

#include "point.h"

//记录下图中能召唤精灵的位置


class Capsule
{
public:
    Capsule(int x,int y);
    int getX()const;
    int getY()const;
    int getWidth()const;
    int getHeight()const;
    int getOccupied()const;
    void setOccupied(const int num);//k:1为萌布布种子;2为萌火猴;3为萌伊尤

private:
    Point _p;                    //位置（左上角的点）
    const int _width=64;         //宽=64像素
    const int _height=64;        //高=64像素
    int _occupied=0;             //判断是否被占了
};

#endif // SPIRITHOUSES_H