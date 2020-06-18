#ifndef PIRATE3_H
#define PIRATE3_H

//海盗3：速度低,但攻击力高,攻击范围大

#include "pirates.h"

class Pirate3 : public Pirates
{
public:
    Pirate3(Point **path, int pathLength, Point &p);
};

#endif // PIRATE3_H