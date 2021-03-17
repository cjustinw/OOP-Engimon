#include "Cell.hpp"

Cell::Cell(Type n_type, char o) {
    type = n_type;
    if (type == SEA) {
        object = 'o';
    } else { 
        object = o;
    }
}

void Cell::setObject(char new_o) {
    object = new_o;
}

char Cell::getObject() const {
    return object;
}

void Cell::setType(Type newType) {
    type = newType;
}

Type Cell::getType() const {
    return type;
}

bool Cell::isEmpty() const {
    return object == '-' || object == 'o';
}

bool Cell::isOccupied() const {
    return !this->isEmpty();
}

bool Cell::isPlayer() const{
    return this->object == 'P';
}

Cell& Cell::operator>>(Cell& other) {
    // cek apakah sel tujuan kosong atau tidak
    if (other.isEmpty()) {
        // jika kosong pindahkan objek ke sel tujuan
        other.setObject(this->getObject());

        // kosongkan sel ini
        if (this->getType() == GRASS) {
            this->setObject('-');
        } else {
            this->setObject('o');
        }
    } 
    // else do nothing
    return *this;
}