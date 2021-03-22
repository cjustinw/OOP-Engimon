#include <iostream>
// #include "Player.hpp"

using namespace std;

int main()
{
    // Point P1;
    // P1.setX(1); P1.setY(2);

    // Player P;
    // Charmander C(1, P1, false);
    // Articuno A(1, P1, false);
    // P.addEngimon(C);
    // P.setActiveEngimon(0);
    // P.setEngimonName(0, "Engimon1");
    // P.addEngimon(A);
    // P.engimonBreed(0,1, "Child Engimon");
    // P.showAllEngimon();
    // cout << P.getNumOfItem() << endl;

    string s = "set active engimon <name engimon>";
    cout << &s[19] << endl;

    return 0;
}

//g++ -o driver.exe driver.cpp Player.cpp ../Engimon/Engimon.cpp ../Point/Point.cpp ../Element/Fire.cpp ../Element/Water.cpp ../Element/Electric.cpp ../Element/Ground.cpp ../Element/Ice.cpp