#ifndef PIRATE6_H
#define PIRATE6_H

//海盗6：攻击力高,攻击速度快,移动速度快

#include "pirates.h"

class Pirate6 : public Pirates
{
public:
    Pirate6(Point **path, int pathLength, Point &p);
};

#endif // PIRATE6_H