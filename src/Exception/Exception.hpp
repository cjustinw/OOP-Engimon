#ifndef _ENGIPTION_HPP_
#define _ENGIPTION_HPP_

#include <exception>
using namespace std;

class ItemNotFoundException : public exception {
public:
    const char * what() const throw() {
        return "Error: Item not found!";
    }
};

class PositionOutOfBoundaryException : public exception {
public:
    const char * what() const throw() {
        return "Error: Invalid position!";
    }
};

class FullInventoryException : public exception {
public:
    const char * what() const throw() {
        return "Your inventory is full!";
    }
};

class SkillItemException : public exception {
public:
    const char * what() const throw() {
        return "You don't have any skill item!";
    }
};

class BattleException : public exception {

};

#endif