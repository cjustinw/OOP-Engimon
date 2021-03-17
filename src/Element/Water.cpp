#include <iostream>
#include "Element.hpp"
#include "Water.hpp"
using namespace std;

Water::Water() {
    Elmt = WATER;
}

float Water::elementAdvantage(ElmtType Elmt) {
    switch (Elmt) {
        case ELECTRIC:
            return 0;
            break;
        case FIRE:
            return 2;
            break;
        default:
            return 1;
            break;
    }
}