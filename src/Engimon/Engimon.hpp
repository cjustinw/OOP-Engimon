#include<string>
using namespace std;

#ifndef _ENGIMON_HPP_
#define _ENGIMON_HPP_

class Engimon
{
    private:
        string name;
        string species;
        //parentNames & species Bagusnya pakai tipe data apa ???
        Element* elements; /* Bagusnya pakai tipe data apa ??? */
        Skill* skills;  /* Bagusnya pakai tipe data apa ??? */
        int level;
        int exp;
        int cumulativeExp;
        bool active;
        Point position;
    public:
        /* Constructor */ 
        Engimon(string name);
        Engimon(const Engimon&);

        /* Desctructor */
        ~Engimon();

        /* Operator */
        void operator=(const Engimon&);

        /* Getter */
        string getName();
        string getSpecies();
        int getCurrentLevel();
        int getCurrentExp();
        Point getPosition();
        int getPower();

        /* Setter */
        void expUp(int);
        void levelUp();
        void learnSkill(Skill);
        void setActive();
        void setPosition();
        void setLevelAfterBreeding();

        /* Conditional Checking */
        bool isMaxCumulativeExp();
        bool isActiveEngimon();
        bool isPositionValid();

        /* Other Methods */
        void status(); 
        void interact();
        Engimon breed(const Engimon&);
        
};

class Bulbasaur : public Engimon
{
    public:
        /* Constructor */ 
        Bulbasaur(string name);
        Bulbasaur(const Bulbasaur&);

        /* Desctructor */
        ~Bulbasaur();

        /* Operator */
        void operator=(const Bulbasaur&);

        /* Other Methods */
        void interact();
};

class Charmander : public Engimon
{
    public:
        /* Constructor */ 
        Charmander(string name);
        Charmander(const Charmander&);

        /* Desctructor */
        ~Charmander();

        /* Operator */
        void operator=(const Charmander&);
 
        /* Other Methods */
        void interact();
};

class Squirtle : public Engimon
{
    public:
        /* Constructor */ 
        Squirtle(string name);
        Squirtle(const Squirtle&);

        /* Desctructor */
        ~Squirtle();

        /* Operator */
        void operator=(const Squirtle&);

        /* Other Methods */
        void interact();
};

/* Nanti ditambah lagi Engimonnya */

#endif