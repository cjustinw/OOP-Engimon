#include "Map.hpp"
 
Map::Map(Point player) {
    length = DEFAULT_LENGTH;
    width = DEFAULT_WIDTH;

    area = new Cell[length*width];
    this->at(player).setObject('P');
}

// cctor
Map::Map(const Map& other) {
    length = other.getLength();
    width = other.getWidth();

    int size = length * width;

    area = new Cell[size];

    for (int i = 0; i < size; i++) {
        area[i] = other.area[i];
    }
}

// operator assignment
Map& Map::operator=(const Map& other) {

    if (this->getSize() != other.getSize()) {
        delete[] area;
        area = new Cell[other.getSize()];
    }
    length = other.getLength();
    width = other.getWidth();

    int size = length * width;
    
    for (int i = 0; i < size; i++) {
        area[i] = other.area[i];
    }

    return *this;
}

// dtor
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

int Map::getSize() const {
    return length * width;
}

void Map::setLength(int new_L) {
    length = new_L;
}

void Map::setWidth(int new_W) {
    width = new_W;
}

// mengembalikan reference sel di posisi (x,y)
Cell& Map::at(int x, int y) const {
    if (x < 1 || x > length || y < 1 || y > length) {
        throw "Out of bound exception.\n";
    }
    return area[(width - y)*length + (x - 1)];
}

Cell& Map::at(Point p) const {
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

/*
void Map::setPlayerPosition(Point player, string option)
{
    int x = player.getX();
    int y = player.getY();
    if (option == "w")
    {    
        this->at(player) >> this->at(x, y+1);
    }
    else if (option == "a")
    {
        this->at(player) >> this->at(x-1, y);
    }
    else if (option == "s")
    {
        this->at(player) >> this->at(x, y-1);
    }
    else if (option == "d")
    {
        this->at(player) >> this->at(x+1, y);
    }
}
*/

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
/*
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
*/
bool Map::isPositionValid(Point P)
{
    if( P.getX() > 0 && P.getX() < length && P.getY() > 0 && P.getY() < width)
    {
        if(this->at(P).getObject() == '-' || this->at(P).getObject() == 'o')
        {
            return true;
        }
    }
    return false;
}

bool Map::isWildEngimonPositionValid(Point P, bool G)
{
    if( P.getX() > 0 && P.getX() < length && P.getY() > 0 && P.getY() < width)
    {
        if(G)
        {
            if(this->at(P).getObject() == '-' || this->at(P).getObject() == 'P')
            {
                return true;
            }
        }
        else
        {
            if(this->at(P).getObject() == 'o' || this->at(P).getObject() == 'P')
            {
                return true;
            }
        }
    }
    return false;
}

// starting state untuk map, spawn beberapa engimon
void Map::initialSpawn() {

}

// semua engimon liar akan move randomly
void Map::update() {

}