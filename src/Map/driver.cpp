#include "Map.hpp"

int main() {
    Map map(15,15);

    map.view();

    cout << map.getLength() << endl;
    cout << map.getWidth() << endl;

    map.at(10,10).setObject('E');
    map.at(15,15).setObject('E');
    map.at(8,6).setObject('E');

    map.view();

    return 0;
}