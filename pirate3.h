#ifndef PIRATE3_H
#define PIRATE3_H

#include "pirates.h"

class Pirate3 : public Pirates
{
public:
    Pirate3(Point **path, int pathLength, Point &p);
};

#endif // PIRATE3_H