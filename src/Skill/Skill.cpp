#include <string>
#include <stdio.h>
#include <vector>
#include "Skill.hpp"
#include"Element.hpp"
using namespace std;

Skill::Skill(){
    this->basePower = 50;
    this->masteryLevel = 0;
}

Skill::Skill(int power, int level, vector<Element*> Elmt){
    this->basePower = power;
    this->masteryLevel = level;
    this->prereqElmt = Elmt;
}

Skill::~Skill(){
    this->basePower=0;
    this->masteryLevel=0;
    delete this->prereqElmt;
}

int Skill::getBasePower(){
    return this->basePower;
}

skillItem::skillItem(){
    this->jumlah=0;
}

skillItem::skillItem(int n){
    this->jumlah=n;
}

int skillItem::getJumlahSkill(){
    return this-> jumlah;
}

void skillItem::useSkill(){
    if (this->jumlah>0) {
        this->jumlah=this->jumlah-1;
    }
}

Blaze::Blaze(){
    this->basePower=50;
    this->masteryLevel=1;
    this->prereqElmt.push_back("FIRE")
}

innerFocus::innerFocus(){
    this->basePower=55;
    this->masteryLevel=1;
    this->prereqElmt.push_back("FIRE")
    this->prereqElmt.push_back("ELECTRIC")
}

lightningRod::lightningRod(){
    this->basePower=56;
    this->masteryLevel=1;
    this->prereqElmt.push_back("ELECTRIC")
}

Pressure::Pressure(){
    this->basePower=55;
    this->masteryLevel=1;
    this->prereqElmt.push_back("FIRE")
}

sandForce::sandForce(){
    this->basePower=57;
    this->masteryLevel=1;
    this->prereqElmt.push_back("GROUND")
}

Drought::Drought(){
    this->basePower=60;
    this->masteryLevel=1;
    this->prereqElmt.push_back("GROUND")
}

rainDish::rainDish(){
    this->basePower=50;
    this->masteryLevel=1;
    this->prereqElmt.push_back("WATER
}

Moxie::Moxie(){
    this->basePower=53;
    this->masteryLevel=1;
    this->prereqElmt.push_back("WATER")
}

iceBody::iceBody(){
    this->basePower=58;
    this->masteryLevel=1;
    this->prereqElmt.push_back("ICE")
}

snowCloak::snowCloak(){
    this->basePower=59;
    this->masteryLevel=1;
    this->prereqElmt.push_back("ICE")
}

BlazeSkill::BlazeSkill(){
    this->jumlah=0;
}

BlazeSkill::learn(){
    
}








