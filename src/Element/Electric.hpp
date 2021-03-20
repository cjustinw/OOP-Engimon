#ifndef _ELECTRIC_H
#define _ELECTRIC_H

#include <iostream>
#include "Element.hpp"

using namespace std;

class Electric: public Element {
public:
    Electric();
    ElmtType getElmt();
    float elementAdvantage(ElmtType Elmt);
};

#endif