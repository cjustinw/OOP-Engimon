#ifndef _ENGIPTION_HPP_
#define _ENGIPTION_HPP_

#include <exception>
using namespace std;

class ItemNotFoundException : public exception {
public:
    const char * what() const throw() {
        return "Item tidak ditemukan";
    }
};

class BattleException : public exception {

};

#endif