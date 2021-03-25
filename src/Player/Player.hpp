#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include<string>
#include "../Point/Point.hpp"
#include "../Engimon/Engimon.hpp"
#include "../Inventory/Inventory.hpp"
#include "../Exception/Exception.hpp"

using namespace std;

class Player
{
    private:
        Inventory<Engimon> engimonInventory;
        Inventory<Skill> skillInventory;
        int maxSkillItem;
        int maxInventory;
        Point position;
        Engimon* activeEngimon;
    
    public:
        /* Constructor */
        Player();

        /* Destructor */
        ~Player();

        /* Getter */
        int getNumOfAllItem();
        int getNumOfSkillItem();
        int getNumOfEngimon();
        Engimon* getActiveEngimon();
        Engimon* getEngimonByIndex(int idx); 
        Skill* getSkillByIndex(int idx);
        Point getPlayerPosition();

        /* Setter */
        void setActiveEngimon(int idx);
        void setEngimonName(int idx, string name);

        /* Conditional Checking */
        bool isInventoryFull();
        Skill* isSkillItemExist(Skill& skill);

        /* Other Methods */
        void addEngimon(Engimon& engimon);
        void removeEngimon(Engimon& engimon);
        void addSkillItem(Skill& skill);
        // void removeSkillItem(Skill& skill);
        void move(string command);
        void showEngimonDescription(int idx);
        void showAllEngimon();
        void showAllSkillItem();
        void showEngimonBySkillItem(Skill& skill);
        void engimonBreed(int idx1, int idx2, string name);
        void useSkillItem(Skill& skill, Engimon& engimon);
};

#endif