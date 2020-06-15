#ifndef PIRATE2_H
#define PIRATE2_H

#include "pirates.h"

class Pirate2 : public Pirates
{
public:
    Pirate2(Point **path, int pathLength, Point &p);
};

#endif // PIRATE2_H