#include <iostream>
#include "Element.hpp"
#include "Ice.hpp"
using namespace std;

Ice::Ice() {
    Elmt = ICE;
}

float Ice::elementAdvantage(ElmtType Elmt) {
    switch (Elmt) {
        case FIRE:
            return 0;
            break;
        case ELECTRIC:
            return 0.5;
            break; 
        case GROUND:
            return 2;
            break;
        default:
            return 1;
            break;
    }
}