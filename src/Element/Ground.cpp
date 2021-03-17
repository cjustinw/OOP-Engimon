#include <iostream>
#include "Element.hpp"
#include "Ground.hpp"
using namespace std;

Ground::Ground() {
    Elmt = GROUND;
}

float Ground::elementAdvantage(ElmtType Elmt) {
    switch (Elmt) {
        case ICE:
            return 0;
            break;
        case FIRE:
            return 1.5;
            break; 
        case ELECTRIC:
            return 2;
            break;
        default:
            return 1;
            break;
    }
}