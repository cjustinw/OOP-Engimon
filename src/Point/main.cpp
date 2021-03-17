#include "Point.hpp"
#include <iostream>

using namespace std;

int main()
{
    Point a;
    a.printPoint();
    a.addX();
    a.printPoint();
    a.addY();
    a.printPoint();
    a.subX();
    a.printPoint();
    a.subY();
    a.printPoint();

    cout << a.getX() << endl;
    cout << a.getY() << endl;

    Point b(2, 3);
    b.printPoint();
    cout << b.getX() << endl;
    cout << b.getY() << endl;
}