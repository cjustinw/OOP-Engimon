#ifndef _WATER_H
#define _WATER_H

#include <iostream>
#include "Element.hpp"
using namespace std;

class Ice: public Element {
public:
    Ice();
    float elementAdvantage(ElmtType Elmt);
};

#endif