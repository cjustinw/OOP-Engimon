#ifndef _ENGIMON_HPP_
#define _ENGIMON_HPP_

#include <string>
#include <vector>
#include "../Element/Element.hpp"
#include "../Element/Electric.hpp"
#include "../Element/Fire.hpp"
#include "../Element/Ground.hpp"
#include "../Element/Ice.hpp"
#include "../Element/Water.hpp"
#include "../Skill/Skill.hpp"
#include "../Point/Point.hpp"
#include "../Exception/Exception.hpp"

using namespace std;

#define MAX_CUMULATIVE_EXP 10000

class Engimon
{
    protected:
        string name;
        string species;
        string parent;
        vector<Element*> elements; 
        vector<Skill*> skills; 
        int ID;
        int maxSkills;
        int numOfSkill;
        int level;
        int exp;
        int cumulativeExp;
        bool active;
        bool child;
        Point position;
        
    public:
        /* Constructor */ 
        Engimon();
        Engimon(int lvl, Point pos, bool child);

        /* Assigment Operator */
        virtual void operator=(const Engimon& other);

        /* Desctructor */
        ~Engimon();

        /* Getter */
        string getName() const;
        string getSpecies() const;
        vector<Element*> getElement() const;
        vector<Skill*> getSkill();
        string getElementName() const;
        string getParent() const;
        int getCurrentLevel() const;
        int getCurrentExp() const;
        Point getPosition() const;
        int getPower(const Engimon& enemy) const;
        int getID() const;
        int getNumOfSkills() const;

        /* Setter */
        void setName(string name);
        void expUp(int);
        void levelUp();
        void learnSkill(Skill* skill);
        void setActive(bool status);
        void setPosition(int,int);
        void setPosition(Point);
        void setLevelAfterBreeding();
        void setParent(string);
        void removeSkillByIndex(int idx);

        /* Conditional Checking */
        bool isMaxCumulativeExp();
        bool isSkillMax();
        bool isActiveEngimon();
        bool isChild();
        bool canBreeding();

        /* Other Methods */
        bool operator==(Engimon& other);
        void showDescription(); 
        virtual void interact();
        Engimon* breed(Engimon&, string);
        
};

/* Fire Type */
class Charmander : public Engimon
{
    public:
        /* Constructor */ 
        Charmander(int lvl, Point pos, bool child);

        /* Assigment Operator */
        void operator=(const Charmander& other);

        /* Desctructor */
        ~Charmander();
 
        /* Other Methods */
        void interact();
};

class Entei : public Engimon
{
    public:
        /* Constructor */ 
        Entei(int lvl, Point pos, bool child);

        /* Assigment Operator */
        void operator=(const Entei& other);

        /* Desctructor */
        ~Entei();
 
        /* Other Methods */
        void interact();
};

/* Electric Type */

class Pikachu : public Engimon
{
    public:
        /* Constructor */ 
        Pikachu(int lvl, Point pos, bool child);

        /* Assigment Operator */
        void operator=(const Pikachu& other);

        /* Desctructor */
        ~Pikachu();
 
        /* Other Methods */
        void interact();
};

class Raikou : public Engimon
{
    public:
        /* Constructor */ 
        Raikou(int lvl, Point pos, bool child);

        /* Assigment Operator */
        void operator=(const Raikou& other);

        /* Desctructor */
        ~Raikou();
 
        /* Other Methods */
        void interact();
};

/* Ground Type */

class Diglet : public Engimon
{
    public:
        /* Constructor */ 
        Diglet(int lvl, Point pos, bool child);

        /* Assigment Operator */
        void operator=(const Diglet& other);

        /* Desctructor */
        ~Diglet();
 
        /* Other Methods */
        void interact();
};

class Groudon : public Engimon
{
    public:
        /* Constructor */ 
        Groudon(int lvl, Point pos, bool child);

        /* Assigment Operator */
        void operator=(const Groudon& other);

        /* Desctructor */
        ~Groudon();
 
        /* Other Methods */
        void interact();
};

/* Water Type */

class Squirtle : public Engimon
{
    public:
        /* Constructor */ 
        Squirtle(int lvl, Point pos, bool child);

        /* Assigment Operator */
        void operator=(const Squirtle& other);

        /* Desctructor */
        ~Squirtle();

        /* Other Methods */
        void interact();
};

class Gyarados : public Engimon
{
    public:
        /* Constructor */ 
        Gyarados(int lvl, Point pos, bool child);

        /* Assigment Operator */
        void operator=(const Gyarados& other);

        /* Desctructor */
        ~Gyarados();

        /* Other Methods */
        void interact();
};

/* Ice Type */

class Glaceon : public Engimon
{
    public:
        /* Constructor */ 
        Glaceon(int lvl, Point pos, bool child);

        /* Assigment Operator */
        void operator=(const Glaceon& other);

        /* Desctructor */
        ~Glaceon();

        /* Other Methods */
        void interact();
};

class Articuno : public Engimon
{
    public:
        /* Constructor */ 
        Articuno(int lvl, Point pos, bool child);

        /* Assigment Operator */
        void operator=(const Articuno& other);

        /* Desctructor */
        ~Articuno();

        /* Other Methods */
        void interact();
};

/* Fire Electric Type */

class Rotom : public Engimon
{
    public:
        /* Constructor */ 
        Rotom(int lvl, Point pos, bool child);

        /* Assigment Operator */
        void operator=(const Rotom& other);

        /* Desctructor */
        ~Rotom();

        /* Other Methods */
        void interact();
};

/* Water Ice Type */

class Lapras : public Engimon
{
    public:
        /* Constructor */ 
        Lapras(int lvl, Point pos, bool child);

        /* Assigment Operator */
        void operator=(const Lapras& other);

        /* Desctructor */
        ~Lapras();

        /* Other Methods */
        void interact();
};

/* Water Ground Type */

class Swampert : public Engimon
{
    public:
        /* Constructor */ 
        Swampert(int lvl, Point pos, bool child);

        /* Assigment Operator */
        void operator=(const Swampert& other);

        /* Desctructor */
        ~Swampert();

        /* Other Methods */
        void interact();
};

Engimon* CreateEngimon(int ID, int lvl, Point pos, bool child);

#endif