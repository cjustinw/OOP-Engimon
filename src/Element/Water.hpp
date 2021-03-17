#ifndef _WATER_H
#define _WATER_H

#include <iostream>
#include "Element.hpp"
using namespace std;

class Water: public Element {
public:
    Water();
    float elementAdvantage(ElmtType Elmt);
};

#endif