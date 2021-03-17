#include <iostream>
#include "Element.hpp"
#include "Fire.hpp"
using namespace std;

Fire::Fire() {
    Elmt = FIRE;
}

float Fire::elementAdvantage(ElmtType Elmt) {
    switch (Elmt) {
        case WATER:
            return 0;
            break;
        case GROUND:
            return 0.5;
            break; 
        case ICE:
            return 2;
            break;
        default:
            return 1;
            break;
    }
}