#include<string>
#include<vector>
#include<iomanip>
#include"../Element/Element.hpp"
#include"../Element/Electric.hpp"
#include"../Element/Fire.hpp"
#include"../Element/Ground.hpp"
#include"../Element/Ice.hpp"
#include"../Element/Water.hpp"
#include"../Point/Point.hpp"

using namespace std;

#ifndef _ENGIMON_HPP_
#define _ENGIMON_HPP_

#define MAX_CUMULATIVE_EXP 1000

class Engimon
{
    protected:
        string name;
        string species;
        string parent;
        vector<Element*> elements; 
        /* vector<Skill> skills; */
        int ID;
        int maxSkills;
        int level;
        int exp;
        int cumulativeExp;
        bool active;
        bool child;
        Point position;
    public:
        /* Constructor */ 
        Engimon(int lvl, Point pos, bool child);

        /* Desctructor */
        ~Engimon();

        /* Getter */
        string getName() const;
        string getSpecies() const;
        vector<Element*> getElement() const;
        string getElementName() const;
        string getParent() const;
        int getCurrentLevel() const;
        int getCurrentExp() const;
        Point getPosition() const;
        int getPower(const Engimon& enemy) const;
        int getID() const;

        /* Setter */
        void setName(string name);
        void expUp(int);
        void levelUp();
        //void learnSkill(Skill);
        void setActive();
        void setPosition(int,int);
        void setLevelAfterBreeding();
        void setParent(string);

        /* Conditional Checking */
        bool isMaxCumulativeExp();
        bool isActiveEngimon();
        bool isPositionValid();
        bool isChild();

        /* Other Methods */
        void showDescription(); 
        virtual void interact();
        Engimon* breed(const Engimon&, string);
        
};
/*

class Bulbasaur : public Engimon
{
    public:
        
        Bulbasaur(string name);

        
        ~Bulbasaur();

    
        void interact();
};

*/

class Charmander : public Engimon
{
    private:
        
    public:
        /* Constructor */ 
        Charmander(int lvl, Point pos, bool child);

        /* Desctructor */
        ~Charmander();
 
        /* Other Methods */
        void interact();
};

class Squirtle : public Engimon
{
    public:
        /* Constructor */ 
        Squirtle(int lvl, Point pos, bool child);

        /* Desctructor */
        ~Squirtle();

        /* Other Methods */
        void interact();
};

/* Nanti ditambah lagi Engimonnya */

Engimon* CreateEngimon(int ID, int lvl, Point pos, bool child);

#endif