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
    if (x < 1 || x > length || y < 1 || y > length) {
        throw "Out of bound exception.\n";
    }
    return area[(width - y)*length + (x - 1)];
}

Cell& Map::at(Point p) {
    return this->at(p.getX(), p.getY());
}

void Map::view() {
    for(int y = width; y >= 1; y--) {
        for(int x = 1; x <= length; x++) {
            cout << this->at(x, y).getObject();
        }
        cout << endl;
    }
}

void Map::moveObject(Point P1, Point P2) {
    this->at(P1) >> this->at(P2);
}

// game-related

Point Map::getPlayerPosition() {
    int x,y;
    bool found = false;

    y = 1;
    while (y <= width && !found) {
        
        x = 1;
        while (x <= length && !found) {
            if (this->at(x,y).isPlayer())
                found = true;
            else {    
                x++;
            }
        }
        
        if (!found) y++;
    }
    // if (!found) {
    //     throw eror
    // } 
    return Point(x,y);
}

void Map::movePlayerUp() {
    Point player = this->getPlayerPosition();
    int x = player.getX();
    int y = player.getY();
    this->at(player) >> this->at(x, y+1);
}

void Map::movePlayerDown() {
    Point player = this->getPlayerPosition();
    int x = player.getX();
    int y = player.getY();
    this->at(player) >> this->at(x, y-1);
}

void Map::movePlayerRight() {
    Point player = this->getPlayerPosition();
    int x = player.getX();
    int y = player.getY();
    this->at(player) >> this->at(x+1, y);
}

void Map::movePlayerLeft() {
    Point player = this->getPlayerPosition();
    int x = player.getX();
    int y = player.getY();
    this->at(player) >> this->at(x-1, y);
}

// starting state untuk map, spawn beberapa engimon
void Map::initialSpawn() {

}

// semua engimon liar akan move randomly
void Map::update() {

}