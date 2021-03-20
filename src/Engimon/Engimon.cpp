#include"Engimon.hpp"

/* Engimon */

Engimon::Engimon(int lvl, Point pos, bool child)
{
    level = lvl;
    exp = 0;
    cumulativeExp = 0;
    active = false;
    this->child = child;
    position.setX(pos.getX());
    position.setY(pos.getY());
}

/* Desctructor */
Engimon::~Engimon()
{
    
}

/* Getter */
string Engimon::getName() const
{
    return name;
}

string Engimon::getSpecies() const
{
    return species;
}

vector<Element*> Engimon::getElement() const
{
    return elements;
}

string Engimon::getElementName() const
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

int Engimon::getCurrentLevel() const
{
    return level;
}

int Engimon::getCurrentExp() const
{
    return exp;
}

Point Engimon::getPosition() const
{
    return position;
}

int Engimon::getPower(const Engimon& enemy) const
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

int Engimon::getID() const
{
    return ID;
}

string Engimon::getParent() const
{
    return parent;
}

/* Setter */
void Engimon::setName(string name)
{
    this->name = name;
}

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

void Engimon::setParent(string S)
{
    this->parent.assign(S);
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

bool Engimon::isChild()
{
    return child;
}

/* Other Methods */
void Engimon::showDescription()
{
    cout << "========================================" << endl
         << "||                Status                  " << endl
         << "========================================" << endl
         << "|| Name        : " << getName()  << endl
         << "|| Species     : " << getSpecies()  << endl
         << "|| Elements    : " << getElementName() << endl;
    if(isChild())
    {
        cout << "|| Parent      : " << getParent() << endl;
    }    
    cout << "|| Skills      : " << endl   
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
    Engimon* E;
    Point P(0,0);
    if(this->elements.size() == 1 && other.elements.size() == 1)
    {
        if(this->getElement()[0]->getElmt() == other.getElement()[0]->getElmt())
        {
           E = CreateEngimon(this->getID(), 0, P, true);
        }
        else
        {
            int thisAdvantage = this->getElement()[0]->elementAdvantage(other.getElement()[0]->getElmt());
            int otherAdvantage = other.getElement()[0]->elementAdvantage(this->getElement()[0]->getElmt());
            if(thisAdvantage > otherAdvantage)
            {
                E = CreateEngimon(this->getID(), 1, P, true);
            }
            else if(thisAdvantage < otherAdvantage)
            {
                E = CreateEngimon(other.getID(), 1, P, true);
            }
            else
            {
                /* Nanti untuk yang anaknya kombinasi elementv*/
            }
        }
    }
    E->setName(name);
    E->setParent("[(" + this->getName() + " : " + this->getSpecies() + ") x (" + other.getName() + " : " + other.getSpecies() + ")]");
    return E;
}

/* Charmander */
Charmander::Charmander(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 1;
    name = "Charmander";
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

Squirtle::Squirtle(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 2;
    name = "Squirtle";
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


Engimon* CreateEngimon(int ID, int lvl, Point pos, bool child)
{
    switch (ID)
    {
    case 1:
        return new Charmander(lvl, pos, child);
    case 2:
        return new Squirtle(lvl, pos, child);
    default:
        return new Engimon(lvl, pos, child);
    }
}