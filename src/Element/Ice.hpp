#ifndef _ICE_H
#define _ICE_H

#include <iostream>
#include "Element.hpp"
using namespace std;

class Ice: public Element {
public:
    Ice();
    ElmtType getElmt();
    float elementAdvantage(ElmtType Elmt);
};

#endif