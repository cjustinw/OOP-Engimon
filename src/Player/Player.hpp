#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include<string>
#include "../Point/Point.hpp"
#include "../Engimon/Engimon.hpp"
#include "../Inventory/Inventory.hpp"

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
        int getNumOfItem();
        int getNumOfEngimon();
        Engimon* getActiveEngimon();
        Engimon* getEngimonByIndex(int idx); 
        Engimon* getEngimonByName(string name); 
        Point getPlayerPosition();

        /* Setter */
        void setActiveEngimon(int idx);
        void setActiveEngimon(string name);
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
        void showEngimonDescription(string name);
        void showAllEngimon();
        void showAllSkillItem();
        void engimonBreed(int idx1, int idx2, string name);
        void engimonBreed(string name1, string name2, string name);
        // void useSkillItem();
};

#endif