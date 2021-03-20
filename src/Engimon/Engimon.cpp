#include"Engimon.hpp"

/* Engimon */

Engimon::Engimon(string name)
{
    this->name = name;
    level = 1;
    exp = 0;
    cumulativeExp = 0;
    active = false;
    position.setX(0);
    position.setY(0);
}

/* Desctructor */
Engimon::~Engimon()
{
    
}

/* Getter */
string Engimon::getName()
{
    return name;
}

string Engimon::getSpecies()
{
    return species;
}

vector<Element*> Engimon::getElement()
{
    return elements;
}

string Engimon::getElementName()
{
    string elmt = "";
    for(int i = 0; i < elements.size(); i++)
    {
        switch (elements[i]->getElmt())
        {
        case FIRE:
            elmt = elmt + "Fire";
            break;
        case ELECTRIC:
            elmt = elmt + "Electric";
            break; 
        case WATER:
            elmt = elmt + "Water";
            break;
        case GROUND:
            elmt = elmt + "Ground";
            break; 
        case ICE:
            elmt = elmt + "Ice";
            break;
        default:
            break;
        }
        if(i < elements.size()-1)
        {
            elmt = elmt + ", ";
        }
    }
    return elmt;
}

int Engimon::getCurrentLevel()
{
    return level;
}

int Engimon::getCurrentExp()
{
    return exp;
}

Point Engimon::getPosition()
{
    return position;
}

int Engimon::getPower(const Engimon& enemy)
{
    int maxAdvantage = 0;
    for(int i = 0; i < this->elements.size(); i++)
    {
        for(int j = 0; j < enemy.elements.size(); j++)
        {
            
            int advantage = this->elements[i]->elementAdvantage(enemy.elements[j]->getElmt());
            if( advantage > maxAdvantage)
            {
                maxAdvantage = advantage;
            }
            
        }
    }
    return this->level * maxAdvantage /* + SUM(every  skill’s  base  power  *  Mastery Level) */;
}

/* Setter */
void Engimon::expUp(int exp)
{
    this->exp += exp;
    cumulativeExp +=exp;
}

void Engimon::levelUp()
{
    int lvl = exp / level*100;
    if(lvl > 0)
    {
        level += lvl;
        exp = exp % lvl*100;
    }
}

//void learnSkill(Skill);
void Engimon::setActive()
{
    active = true;
}

void Engimon::setPosition(int x, int y)
{
    position.setX(x);
    position.setY(y);
}

void Engimon::setLevelAfterBreeding()
{
    level -= 30;
}

/* Conditional Checking */
bool Engimon::isMaxCumulativeExp()
{
    return exp >= MAX_CUMULATIVE_EXP;
}

bool Engimon::isActiveEngimon()
{
    return active;
}

bool Engimon::isPositionValid()
{
    /* dari class map ada method cek position valid? */
}

/* Other Methods */
void Engimon::showDescription()
{
    cout << "========================================" << endl
         << "||                Status                  " << endl
         << "========================================" << endl
         << "|| Name        : " << getName()  << endl
         << "|| Species     : " << getSpecies()  << endl
         << "|| Elements    : " << getElementName() << endl
         << "|| Parent      : " << endl 
         << "|| Skills      : " << endl   
         << "|| Level       : " << getCurrentLevel() <<endl
         << "|| EXP         : " << getCurrentExp() << endl
         << "========================================" << endl;
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
    // this->elements.push_back();
    // this->skills.push_back();
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
    species = "Charmander";
    elements.push_back(new Fire());
    // this->skills.push_back();
}

/* Desctructor */
Charmander::~Charmander()
{
    
}

/* Other Methods */
void Charmander::interact()
{
    cout << "Charmander: " << endl;
}

/* Squirtle */

Squirtle::Squirtle(string name) : Engimon(name)
{
    species = "Squirtle";
    elements.push_back(new Water());
    // this->skills.push_back();
}

/* Desctructor */
Squirtle::~Squirtle()
{

}

/* Other Methods */
void Squirtle::interact()
{
    cout << "Squirtle: " << endl;
}
