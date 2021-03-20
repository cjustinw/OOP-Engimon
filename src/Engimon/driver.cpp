#include "Engimon.hpp"

int main()
{
    Charmander* C = new Charmander("Engimon1");
    Squirtle* S = new Squirtle("Engimon2");

    C->showDescription();
    S->showDescription();

    cout << "Charmader Advantage Element : " << C->getPower(*S) << endl;
    cout << "Squirtle Advantage Element  : " << S->getPower(*C) << endl;

    //g++ -o driver.exe driver.cpp Engimon.cpp ../Point/Point.cpp ../Element/Fire.cpp ../Element/Water.cpp

    return 0;
}