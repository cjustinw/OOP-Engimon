#ifndef _CELL_H_
#define _CELL_H_

#include <vector>
#include <iostream>

using namespace std;

enum Type {GRASS, SEA};

class Cell {
private:
    /* data */
    Type type; // tipe dari sel GRASS atau SEA
    char object; // objek yang ada pada sel

public:
    // user-defined constructor
    Cell(Type n_type = GRASS, char o = '-');

    // selektor-objek
    void setObject(char new_o);
    char getObject() const ;

    // selektor tipe sel
    void setType(Type newType);
    Type getType() const ;

    // predikat
    bool isEmpty() const;
    bool isOccupied() const;
    bool isPlayer() const;

    // operator overload >>,
    // untuk memindahkan objek pada sel ini ke sel lain 
    Cell& operator>>(Cell& other);
};

#endif