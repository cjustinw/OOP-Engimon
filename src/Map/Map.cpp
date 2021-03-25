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
    for(int y = width+1; y >= 0; y--) {
        if(y == width+1)
        {
            for(int x = 0; x <= length+1; x++) {
                cout << "_";
            }
        }
        else if( y == 0)
        {
            for(int x = 0; x <= length+1; x++) {
                if(x == 0 || x == length+1)
                {
                    cout << "|" ;
                }
                else
                {
                    cout << "_";
                }
            }
        }
        else
        {
            for(int x = 0; x <= length+1; x++) {
                if(x == 0 || x == length+1)
                {
                    cout << "|" ;
                }
                else
                {
                    cout << this->at(x, y).getObject();
                }
            }
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

bool Map::isPositionValid(Point P)
{
    if( P.getX() > 0 && P.getX() <= length && P.getY() > 0 && P.getY() <= width)
    {
        if(this->at(P).getObject() == '-' || this->at(P).getObject() == 'o')
        {
            return true;
        }
    }
    return false;
}
