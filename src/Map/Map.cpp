#include "Map.hpp"
 
Map::Map(int len, int wid) {
    length = len;
    width = wid;

    area = new Cell[length*width];

    this->at(1,1).setObject('P');
}

Map::~Map() {
    delete[] area;
}

// selektor
int Map::getLength() const {
    return length;
}

int Map::getWidth() const {
    return width;
}

void Map::setLength(int new_L) {
    length = new_L;
}

void Map::setWidth(int new_W) {
    width = new_W;
}

// mengembalikan reference sel di posisi (x,y)
Cell& Map::at(int x, int y) {
    return area[(width - y)*length + (x - 1)];
}

void Map::view() {
    for(int y = width; y >= 1; y--) {
        for(int x = 1; x <= length; x++) {
            cout << this->at(x, y).getObject();
        }
        cout << endl;
    }
}

// game-related

Point Map::getPlayerPosition() {
    int x, y;
    bool found = false;
    while (y <= width && !found) {
        while (x <= length && !found) {
            if (this->at(x,y).isPlayer())
                found = true;
            x++;
        }
        y++;
    }
    // if (!found) {
    //     throw eror
    // } 
    return Point(x,y);
}

void Map::movePlayerUp() {}
void Map::movePlayerDown() {}
void Map::movePlayerRight() {}
void Map::movePlayerLeft() {}

// starting state untuk map, spawn beberapa engimon
void Map::initialSpawn() {

}

// semua engimon liar akan move randomly
void Map::update() {

}