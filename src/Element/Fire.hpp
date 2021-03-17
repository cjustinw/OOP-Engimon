#ifndef _FIRE_H
#define _FIRE_H

#include <iostream>
#include "Element.hpp"
using namespace std;

class Fire: public Element {
public:
    Fire();
    float elementAdvantage(ElmtType Elmt);
};

#endif