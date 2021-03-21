#include <string>
#include <stdio.h>
#include "Skill.hpp"
using namespace std;

Skill::Skill(){
    this->basePower = 50;
    this->masteryLevel = 0;
    this->prereqElmt = NULL;
}

Skill::Skill(int power, int level, Element* Elmt){
    this->basePower = power;
    this->masteryLevel = level;
    this->prereqElmt = Elmt;
}

Skill::~Skill(){
    this->basePower=0;
    this->masteryLevel=0;
    delete this->prereqElmt;
}

Skill::getBasePower(){
    return this->basePower;
}









