#include<string>
#include"../Element/Element.hpp"
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
        //parentNames & species Bagusnya pakai tipe data apa ???
        string species;
        Element* elements; /* Bagusnya pakai tipe data apa ??? */
        /* Skill* skills;   Bagusnya pakai tipe data apa ??? */
        int numOfElmts;
        int numOfSkills;
        int level;
        int exp;
        int cumulativeExp;
        bool active;
        Point position;
    public:
        /* Constructor */ 
        Engimon(string name);

        /* Desctructor */
        ~Engimon();

        /* Getter */
        string getName();
        string getSpecies();
        Element* getElement();
        int getCurrentLevel();
        int getCurrentExp();
        Point getPosition();
        int getPower(const Engimon& enemy);

        /* Setter */
        void expUp(int);
        void levelUp();
        //void learnSkill(Skill);
        void setActive();
        void setPosition(int,int);
        void setLevelAfterBreeding();

        /* Conditional Checking */
        bool isMaxCumulativeExp();
        bool isActiveEngimon();
        bool isPositionValid();

        /* Other Methods */
        void status(); 
        virtual void interact();
        Engimon* breed(const Engimon&, string);
        
};

class Bulbasaur : public Engimon
{
    public:
        /* Constructor */ 
        Bulbasaur(string name);

        /* Desctructor */
        ~Bulbasaur();

        /* Other Methods */
        void interact();
};

class Charmander : public Engimon
{
    public:
        /* Constructor */ 
        Charmander(string name);

        /* Desctructor */
        ~Charmander();
 
        /* Other Methods */
        void interact();
};

class Squirtle : public Engimon
{
    public:
        /* Constructor */ 
        Squirtle(string name);

        /* Desctructor */
        ~Squirtle();

        /* Other Methods */
        void interact();
};

/* Nanti ditambah lagi Engimonnya */

#endif