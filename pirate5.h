#ifndef PIRATE5_H
#define PIRATE5_H

//海盗5：速度快,攻击力高,但攻击速度慢

#include "pirates.h"

class Pirate5 : public Pirates
{
public:
    Pirate5(Point **path, int pathLength, Point &p);
};

#endif // PIRATE5_H