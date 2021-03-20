#include <iostream>
#include "Element.hpp"
#include "Electric.hpp"
using namespace std;

Electric::Electric() {
    Elmt = ELECTRIC;
}

ElmtType Electric::getElmt() {
    return ELECTRIC;
}

float Electric::elementAdvantage(ElmtType Elmt) {
    switch (Elmt) {
        case GROUND:
            return 0;
            break;
        case ICE:
            return 1.5;
            break; 
        case WATER:
            return 2;
            break;
        default:
            return 1;
            break;
    }
}