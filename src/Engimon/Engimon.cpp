#include"Engimon.hpp"

/* Engimon */

Engimon::Engimon(string name)
{
    this->name = name;
    this->level = 1;
    this->exp = 0;
    this->cumulativeExp = 0;
    this->active = false;
    this->position.setX(0);
    this->position.setY(0);
}

/* Desctructor */
Engimon::~Engimon()
{
    delete this->elements;
    // delete this->skills;
}

/* Getter */
string Engimon::getName()
{
    return this->name;
}

string Engimon::getSpecies()
{
    return this->species;
}

Element* Engimon::getElement()
{
    return this->elements;
}

int Engimon::getCurrentLevel()
{
    return this->level;
}

int Engimon::getCurrentExp()
{
    return this->exp;
}

Point Engimon::getPosition()
{
    return this->position;
}

int Engimon::getPower(const Engimon& enemy)
{
    int maxAdvantage = 0;
    for(int i = 0; i < this->numOfSkills; i++)
    {
        for(int j = 0; j < enemy.numOfElmts; j++)
        {
            /*
            int advantage = this->elements[i].elementAdvantage(enemy.elements[j]);
            if( advantage > maxAdvantage)
            {
                maxAdvantage = advantage;
            }
            */
        }
    }
    return this->level * maxAdvantage /* + SUM(every  skill’s  base  power  *  Mastery Level) */;
}

/* Setter */
void Engimon::expUp(int exp)
{
    this->exp += exp;
    this->cumulativeExp +=exp;
}

void Engimon::levelUp()
{
    if(this->exp >= this->level*100)
    {
        this->exp -= this->level*100;
        this->level++;
    }
}

//void learnSkill(Skill);
void Engimon::setActive()
{
    this->active = true;
}

void Engimon::setPosition(int x, int y)
{
    this->position.setX(x);
    this->position.setY(y);
}

void Engimon::setLevelAfterBreeding()
{
    this->level -= 30;
}

/* Conditional Checking */
bool Engimon::isMaxCumulativeExp()
{
    return this->exp >= MAX_CUMULATIVE_EXP;
}

bool Engimon::isActiveEngimon()
{
    return this->active;
}

bool Engimon::isPositionValid()
{
    /* dari class map ada method cek position valid? */
}

/* Other Methods */
void Engimon::status()
{
    cout << "Status " << endl;
    cout << "Name           : " << endl;
    cout << "Elements       : " << endl;
    cout << "Parent         : " << endl;
    cout << "Skills         : " << endl;
    cout << "Level          : " << endl;
    cout << "EXP            : " << endl;
}

void Engimon::interact()
{
    cout << "Pika-pika~" << endl;
}

Engimon* Engimon::breed(const Engimon& other, string name)
{
    /* */
}

/* Bulbasaur */

Bulbasaur::Bulbasaur(string name) : Engimon(name)
{

}

/* Desctructor */
Bulbasaur::~Bulbasaur()
{
    
}

/* Other Methods */
void Bulbasaur::interact()
{
    cout << "Aaaaaaa.... " << endl;
}

/* Charmander */

Charmander::Charmander(string name) : Engimon(name)
{

}

/* Desctructor */
Charmander::~Charmander()
{

}

/* Other Methods */
void Charmander::interact()
{
    cout << "Bbbbbbb.... " << endl;
}

/* Squirtle */

Squirtle::Squirtle(string name) : Engimon(name)
{

}

/* Desctructor */
Squirtle::~Squirtle()
{

}

/* Other Methods */
void Squirtle::interact()
{
    cout << "Ccccccc.... " << endl;
}
