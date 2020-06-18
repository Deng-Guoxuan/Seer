#ifndef PIRATE7_H
#define PIRATE7_H

//海盗7：移动速度快,攻击力高,攻击范围大,且子弹具有穿透效果。(是精灵英卡洛斯的兄弟)

#include "pirates.h"

class Pirate7 : public Pirates
{
public:
    Pirate7(Point **path, int pathLength, Point &p);
};

#endif // PIRATE7_H