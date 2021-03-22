#include "Player.hpp"
#include <iostream>

using namespace std;

Player::Player()
{
    position.setX(1);
    position.setY(1);
    maxSkillItem = 4;
    maxInventory = 15;
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
    if(activeEngimon != NULL)
    {
        activeEngimon->setActive(false);
    }
    activeEngimon = getEngimonByIndex(idx);
    activeEngimon->setActive(true);
}

void Player::setActiveEngimon(string name)
{
    if(activeEngimon != NULL)
    {
        activeEngimon->setActive(false);
    }
    activeEngimon = getEngimonByName(name);
    activeEngimon->setActive(true);
}

void Player::setEngimonName(int idx, string name)
{
    getEngimonByIndex(idx)->setName(name);
}

bool Player::isInventoryFull()
{
    return (getNumOfItem() >= maxInventory);
}

void Player::addEngimon(Engimon& engimon)
{
    engimonInventory.add(engimon);
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
    for(int i = 0; i < engimonInventory.getNumOfElement(); i++)
    {
        cout << engimonInventory[i].getName() << " (" << engimonInventory[i].getSpecies()  << ")" << endl;
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