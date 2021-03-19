#include "Map.hpp"

int main() {
    Point player(1,1);
    Map map(player);
    string choice;

    map.view();

    cout << map.getLength() << endl;
    cout << map.getWidth() << endl;

    map.at(10,10).setObject('E');
    map.at(15,15).setObject('E');
    map.at(8,6).setObject('E');

    map.view();
    player.printPoint();
    while (1) {
        try {
            cin >> choice;     
            map.setPlayerPosition(player, choice);

            map.view();
            map.getPlayerPosition().printPoint();   
        } 
        catch (char const * s) {
            map.view();
            map.getPlayerPosition().printPoint();             
            cout << s;
        }
    }

    return 0;
}

/*
g++ -c *.cpp ../Point/Point.cpp

g++ -o driver driver.cpp Map.o Cell.o Point.o
*/