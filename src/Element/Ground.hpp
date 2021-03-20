#ifndef _GROUND_H
#define _GROUND_H

#include <iostream>
#include "Element.hpp"
using namespace std;

class Ground: public Element {
public:
    Ground();
    ElmtType getElmt();
    float elementAdvantage(ElmtType Elmt);
};

#endif