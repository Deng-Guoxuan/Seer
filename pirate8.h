#ifndef PIRATE8_H
#define PIRATE8_H

//Boss海盗：速度较快,血量很高,攻击范围一般,攻击速度较慢,但是没有任何精灵能够挡住他的一次攻击

#include "pirates.h"

class Pirate8 : public Pirates
{
public:
    Pirate8(Point **path, int pathLength, Point &p);
};

#endif // PIRATE8_H