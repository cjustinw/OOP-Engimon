#ifndef _ENGIPTION_HPP_
#define _ENGIPTION_HPP_

#include <exception>
using namespace std;

class Exception {
public:
    virtual const char * what() const throw() = 0;
};

class InvalidInputException : public Exception {
public:
    const char * what() const throw() {
        return "Error: Invalid input!";
    }
};

class ItemNotFoundException : public Exception {
public:
    const char * what() const throw() {
        return "Error: Item not found!";
    }
};

class PositionOutOfBoundaryException : public Exception {
public:
    const char * what() const throw() {
        return "Error: Invalid position!";
    }
};

class FullInventoryException : public Exception {
public:
    const char * what() const throw() {
        return "Your inventory is full!";
    }
};

class SkillItemException : public Exception {
public:
    const char * what() const throw() {
        return "You don't have any skill item!";
    }
};

class EngimonException : public Exception {
public:
    const char * what() const throw() {
        return "You don't have any other engimon !";
    }
};

class BreedingLevelException : public Exception {
public:
    const char * what() const throw() {
        return "Your engimon must reach level 31 before start breeding!";
    }
};


#endif