#include "Player.hpp"
#include <iostream>

using namespace std;

Player::Player()
{
    position.setX(1);
    position.setY(1);
    maxSkillItem = 4;
    maxInventory = 100;
    activeEngimon = NULL;
}

Player::~Player()
{
    delete &engimonInventory;
}

int Player::getNumOfItem()
{
    return engimonInventory.getNumOfElement() /* + skillInventory.getNumOfElemet() */ ;
}

int Player::getNumOfEngimon()
{
    return engimonInventory.getNumOfElement();
}

Engimon* Player::getActiveEngimon()
{
    return activeEngimon;
}

Engimon* Player::getEngimonByIndex(int idx)
{
    return &engimonInventory[idx];
}

Engimon* Player::getEngimonByName(string name)
{
    if(engimonInventory.getNumOfElement() == 0)
    {
        // throw;
    }
    for(int i = 0; i < engimonInventory.getNumOfElement(); i++)
    {
        if(engimonInventory[i].getName() == name)
        {
            return &engimonInventory[i];
        }
    }
}

Point Player::getPlayerPosition()
{
    return this->position;
}

void Player::setActiveEngimon(int idx)
{
    Point P(2,1);
    if(activeEngimon != NULL)
    {
        
        activeEngimon->setActive(false);
        P.setX(activeEngimon->getPosition().getX());
        P.setY(activeEngimon->getPosition().getY());
        activeEngimon->setPosition(0,0);
    }
    activeEngimon = getEngimonByIndex(idx);
    activeEngimon->setActive(true);
    activeEngimon->setPosition(P);
}

void Player::setActiveEngimon(string name)
{
    Point P(2,1);
    if(activeEngimon != NULL)
    {
        activeEngimon->setActive(false);
        P.setX(activeEngimon->getPosition().getX());
        P.setY(activeEngimon->getPosition().getY());
        activeEngimon->setPosition(0,0);
    }
    activeEngimon = getEngimonByName(name);
    activeEngimon->setActive(true);
    activeEngimon->setPosition(P);
}

void Player::setEngimonName(int idx, string name)
{
    getEngimonByIndex(idx)->setName(name);
}

bool Player::isInventoryFull()
{
    return (getNumOfItem() >= maxInventory);
}

Skill* Player::isSkillItemExist(Skill& skill)
{
    for(int i = 0; i < skillInventory.getNumOfElement(); i++)
    {
        if(skillInventory[i].getSkillName() == skill.getSkillName())
        {
            return &skillInventory[i];
        }
    }
    return NULL;
}

void Player::addEngimon(Engimon& engimon)
{
    engimon.setPosition(0,0);
    engimonInventory.add(engimon);
}

void Player::removeEngimon(Engimon& engimon)
{
    if(*getActiveEngimon() == engimon)
    {
        activeEngimon = NULL;
    }
    for(int i = 0; i< engimonInventory.getNumOfElement(); i++)
    {
        if(engimonInventory[i] == engimon)
        {
            engimonInventory.delAt(i);
            break;
        }
    }
}

void Player::addSkillItem(Skill& skill)
{
    skillInventory.add(skill);
}

void Player::move(string command)
{
    activeEngimon->setPosition(getPlayerPosition());
    if (command == "w")
    {
        position.addY();
    }
    else if (command == "a")
    {
        position.subX();
    }
    else if (command == "s")
    {
        position.subY();
    }
    else if (command == "d")
    {
        position.addX();
    }
    else
    {
        // throw error
    }
} 

void Player::showEngimonDescription(int idx)
{
    getEngimonByIndex(idx)->showDescription();
}

void Player::showEngimonDescription(string name)
{
    getEngimonByName(name)->showDescription();
}

void Player::showAllEngimon()
{
    cout << "Engimon list: " << endl;
    for(int i = 0; i < engimonInventory.getNumOfElement(); i++)
    {
        cout << "   " << i+1 << ". "<< engimonInventory[i].getName() << " (" << engimonInventory[i].getSpecies()  << ")" << " Lvl." << engimonInventory[i].getCurrentLevel() <<endl;
    }
}

void Player::showAllSkillItem()
{
    cout << "Skill Item list: " << endl;
    for(int i = 0; i < skillInventory.getNumOfElement(); i++)
    {
        cout << "   " << i+1 << ". "<< skillInventory[i].getSkillName() << " (x" << skillInventory[i].getNumOfItem()  << ")"  <<endl;
    }
}

void Player::engimonBreed(int idx1, int idx2, string name)
{
    addEngimon(*getEngimonByIndex(idx1)->breed(*getEngimonByIndex(idx2), name));
}

void Player::engimonBreed(string name1, string name2, string name)
{
    addEngimon(*getEngimonByName(name1)->breed(*getEngimonByName(name2), name));
}