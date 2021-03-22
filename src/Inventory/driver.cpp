#include <iostream>
#include "../Point/Point.hpp"
#include "../Engimon/Engimon.hpp"
#include "Inventory.hpp"

using namespace std;

int main()
{
    Point P1;
    P1.setX(1);
    P1.setY(1);
    Point P2;
    P1.setX(2);
    P1.setY(2);
    Point P3;
    P1.setX(3);
    P1.setY(3);
    Charmander C(1, P1, false);
    Entei E(1, P2, false);

    Inventory<Engimon> I1;
    I1.add(C);
    I1.add(E);
    
    I1[0].showDescription();
    I1[1].showDescription();
    cout << I1.getNumOfElement() << endl;

    Inventory<Engimon> I2;
    Gyarados G(1, P1, false);
    Articuno A(1, P3, false);
    I2.add(G);
    I2.add(A);
    I2[0].showDescription();
    I1[1].showDescription();
    cout << I2.getNumOfElement() << endl;

    return 0;
}

//g++ -o driver.exe driver.cpp ../Engimon/Engimon.cpp ../Point/Point.cpp ../Element/Fire.cpp ../Element/Water.cpp ../Element/Electric.cpp ../Element/Ground.cpp ../Element/Ice.cpp