#include "Map.hpp"

int main() {
    Map map(15,15);
    char choice;

    map.view();

    cout << map.getLength() << endl;
    cout << map.getWidth() << endl;

    map.at(10,10).setObject('E');
    map.at(15,15).setObject('E');
    map.at(8,6).setObject('E');

    map.view();
    map.getPlayerPosition().printPoint();
    while (1) {
        try {
            cin >> choice;     
            switch (choice) {
            case 'w':
                map.movePlayerUp();
                break;
            
            case 'd':
                map.movePlayerRight();
                break;

            case 'a':
                map.movePlayerLeft();
                break;

            case 's':
                map.movePlayerDown();
                break;

            case 'q':
                exit(0);

            default:
                break;
            }

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