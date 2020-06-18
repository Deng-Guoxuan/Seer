#ifndef PIRATE2_H
#define PIRATE2_H

//海盗2：比1强一点点,速度较快

#include "pirates.h"

class Pirate2 : public Pirates
{
public:
    Pirate2(Point **path, int pathLength, Point &p);
};

#endif // PIRATE2_H