#ifndef PIRATE1_H
#define PIRATE1_H

#include "pirates.h"

class Pirate1 : public Pirates
{
public:
    Pirate1(Point **path, int pathLength, Point &p);
};

#endif // PIRATE1_H