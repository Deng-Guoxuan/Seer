#ifndef PIRATE4_H
#define PIRATE4_H

//海盗4：各项指标均中等

#include "pirates.h"

class Pirate4 : public Pirates
{
public:
    Pirate4(Point **path, int pathLength, Point &p);
};


#endif // PIRATE4_H