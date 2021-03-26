#ifndef _ENGIPTION_HPP_
#define _ENGIPTION_HPP_

#include <exception>
using namespace std;

class InvalidInputException : public exception {
public:
    const char * what() const throw() {
        return "Error: Invalid input!";
    }
};

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

class EngimonException : public exception {
public:
    const char * what() const throw() {
        return "You don't have any other engimon !";
    }
};

class BreedingLevelException : public exception {
public:
    const char * what() const throw() {
        return "Your engimon must reach level 31 before start breeding!";
    }
};

class BattleException : public exception {

};

#endif