#include "Engimon.hpp"

int main()
{
    Point P1(1,1);
    Point P2(2,7);
    Charmander* C = new Charmander(1,P1,false);
    C->setName("Engimon1");

    Engimon* C2;
    C2 = C;

    C->showDescription();
    C2->showDescription();

    // Charmander* C2 = new Charmander(1,P2,false);
    // C2->setName("Engimon2");
    // Squirtle* S = new Squirtle(3,P2,true);
    // S->setName("Engimon2");

    // Engimon* E;
    // E = C->breed(*S, "Engimon3");

    // E->showDescription();

    // cout << "Charmader Advantage Element : " << C->getPower(*S) << endl;
    // cout << "Squirtle Advantage Element  : " << S->getPower(*C) << endl;

    //g++ -o driver.exe driver.cpp Engimon.cpp ../Point/Point.cpp ../Element/Fire.cpp ../Element/Water.cpp ../Element/Electric.cpp ../Element/Ground.cpp ../Element/Ice.cpp

    return 0;
}