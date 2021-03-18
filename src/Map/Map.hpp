#ifndef _MAP_HPP_
#define _MAP_HPP_

#include "Cell.hpp"
#include "../Point/Point.hpp"
#include <string>
#include <iostream>

using namespace std;

#define DEFAULT_LENGTH 30
#define DEFAULT_WIDTH 30


//**** Struktur Map ****//
/*
    ---------------------
    |          (max,max)|
    |                   |
    |                   |
    |                   |
    |                   |
    |                   |
    |                   |
    | (1,1)             |
    ---------------------
*/
//**********************//


class Map {
private:
    /* data */
    int length;
    int width;

    Cell *area;

public:
    Map(int len = DEFAULT_LENGTH, int wid = DEFAULT_WIDTH);
    ~Map();

    // selektor
    int getLength() const;
    int getWidth() const;

    void setLength(int new_L);
    void setWidth(int new_W);

    // mengembalikan reference sel di posisi (x,y)
    Cell& at(int x, int y);
    Cell& at(Point P);

    void view();

    // memindahkan object dari posisi P1 ke P2
    void moveObject(Point P1, Point P2);

    // game-related
    Point getPlayerPosition();

    void movePlayerUp();
    void movePlayerDown();
    void movePlayerRight();
    void movePlayerLeft();

    // starting state untuk map, spawn beberapa engimon
    void initialSpawn();
    
    // semua engimon liar akan move randomly
    void update();
};

#endif