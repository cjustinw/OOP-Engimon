#ifndef _ELEMENT_H
#define _ELEMENT_H

#include <iostream>
using namespace std;

enum ElmtType {FIRE, WATER, ELECTRIC, GROUND, ICE};

class Element {
protected:
    ElmtType Elmt;

public:
    virtual float elementAdvantage(ElmtType Elmt) = 0;
};

#endif