#include"Engimon.hpp"

/* Engimon */

Engimon::Engimon()
{
    
}

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

/* Assigment Operator */

void Engimon::operator=(const Engimon& other)
{
    level = other.level;
    exp = other.exp;
    cumulativeExp = other.cumulativeExp;
    active = other.active;
    child = other.child;
    position.setX(other.getPosition().getX());
    position.setY(other.getPosition().getY());
}

/* Desctructor */
Engimon::~Engimon()
{
    delete &elements;
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

void Engimon::setActive(bool status)
{
    active = status;
}

void Engimon::setPosition(int x, int y)
{
    position.setX(x);
    position.setY(y);
}

void Engimon::setPosition(Point P)
{
    position.setX(P.getX());
    position.setY(P.getY());
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

bool Engimon::isChild()
{
    return child;
}

/* Other Methods */
void Engimon::showDescription()
{
    cout << "========================================" << endl
         << "                  Status                  " << endl
         << "========================================" << endl
         << "   Name        : " << getName()  << endl
         << "   Species     : " << getSpecies()  << endl
         << "   Elements    : " << getElementName() << endl;
    if(isChild())
    {
        cout << "   Parent      : " << getParent() << endl;
    }    
    cout << "   Skills      : " << endl   
         << "   Level       : " << getCurrentLevel() <<endl
         << "   EXP         : " << getCurrentExp() << endl
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
                /* Nanti untuk yang anaknya kombinasi element */
            }
        }
    }
    E->setName(name);
    E->setParent(this->getName() + " (" + this->getSpecies() + "), " + other.getName() + " (" + other.getSpecies() + ")");
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

 void Charmander::operator=(const Charmander& other)
 {
    this->operator=(other);
    ID = other.getID();
    name = other.getName();
    species = other.getSpecies();
    elements.push_back(other.getElement()[0]);
 }

Charmander::~Charmander()
{
    
}

void Charmander::interact()
{
    cout << "Charmander: " << endl;
}

/* Entei */
Entei::Entei(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 2;
    name = "Entei";
    species = "Entei";
    elements.push_back(new Fire());
    // this->skills.push_back();
}

void Entei::operator=(const Entei& other)
 {
    this->operator=(other);
    ID = other.getID();
    name = other.getName();
    species = other.getSpecies();
    elements.push_back(other.getElement()[0]);
 }

Entei::~Entei()
{
    
}

void Entei::interact()
{
    cout << "Entei: " << endl;
}

/* Pikachu */
Pikachu::Pikachu(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 3;
    name = "Pikachu";
    species = "Pikachu";
    elements.push_back(new Electric());
    // this->skills.push_back();
}

void Pikachu::operator=(const Pikachu& other)
 {
    this->operator=(other);
    ID = other.getID();
    name = other.getName();
    species = other.getSpecies();
    elements.push_back(other.getElement()[0]);
 }

Pikachu::~Pikachu()
{
    
}

void Pikachu::interact()
{
    cout << "Pikachu: " << endl;
}

/* Raikou */
Raikou::Raikou(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 4;
    name = "Raikou";
    species = "Raikou";
    elements.push_back(new Electric());
    // this->skills.push_back();
}

void Raikou::operator=(const Raikou& other)
 {
    this->operator=(other);
    ID = other.getID();
    name = other.getName();
    species = other.getSpecies();
    elements.push_back(other.getElement()[0]);
 }

Raikou::~Raikou()
{
    
}

void Raikou::interact()
{
    cout << "Raikou: " << endl;
}

/* Diglet */
Diglet::Diglet(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 5;
    name = "Diglet";
    species = "Diglet";
    elements.push_back(new Ground());
    // this->skills.push_back();
}

void Diglet::operator=(const Diglet& other)
 {
    this->operator=(other);
    ID = other.getID();
    name = other.getName();
    species = other.getSpecies();
    elements.push_back(other.getElement()[0]);
 }

Diglet::~Diglet()
{
    
}

void Diglet::interact()
{
    cout << "Diglet: " << endl;
}

/* Groudon */
Groudon::Groudon(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 6;
    name = "Groudon";
    species = "Groudon";
    elements.push_back(new Ground());
    // this->skills.push_back();
}

void Groudon::operator=(const Groudon& other)
 {
    this->operator=(other);
    ID = other.getID();
    name = other.getName();
    species = other.getSpecies();
    elements.push_back(other.getElement()[0]);
 }

Groudon::~Groudon()
{
    
}

void Groudon::interact()
{
    cout << "Groudon: " << endl;
}

/* Squirtle */
Squirtle::Squirtle(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 7;
    name = "Squirtle";
    species = "Squirtle";
    elements.push_back(new Water());
    // this->skills.push_back();
}

void Squirtle::operator=(const Squirtle& other)
 {
    this->operator=(other);
    ID = other.getID();
    name = other.getName();
    species = other.getSpecies();
    elements.push_back(other.getElement()[0]);
 }

Squirtle::~Squirtle()
{

}

void Squirtle::interact()
{
    cout << "Squirtle: " << endl;
}

/* Gyarados */
Gyarados::Gyarados(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 8;
    name = "Gyarados";
    species = "Gyarados";
    elements.push_back(new Water());
    // this->skills.push_back();
}

void Gyarados::operator=(const Gyarados& other)
 {
    this->operator=(other);
    ID = other.getID();
    name = other.getName();
    species = other.getSpecies();
    elements.push_back(other.getElement()[0]);
 }

Gyarados::~Gyarados()
{

}

void Gyarados::interact()
{
    cout << "Gyarados: " << endl;
}

/* Glaceon */
Glaceon::Glaceon(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 9;
    name = "Glaceon";
    species = "Glaceon";
    elements.push_back(new Ice());
    // this->skills.push_back();
}

void Glaceon::operator=(const Glaceon& other)
 {
    this->operator=(other);
    ID = other.getID();
    name = other.getName();
    species = other.getSpecies();
    elements.push_back(other.getElement()[0]);
 }

Glaceon::~Glaceon()
{

}

void Glaceon::interact()
{
    cout << "Glaceon: " << endl;
}

/* Articuno */
Articuno::Articuno(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 10;
    name = "Articuno";
    species = "Articuno";
    elements.push_back(new Ice());
    // this->skills.push_back();
}

void Articuno::operator=(const Articuno& other)
 {
    this->operator=(other);
    ID = other.getID();
    name = other.getName();
    species = other.getSpecies();
    elements.push_back(other.getElement()[0]);
 }

Articuno::~Articuno()
{

}

void Articuno::interact()
{
    cout << "Articuno: " << endl;
}

Engimon* CreateEngimon(int ID, int lvl, Point pos, bool child)
{
    switch (ID)
    {
    case 1:
        return new Charmander(lvl, pos, child);
    case 2:
        return new Entei(lvl, pos, child);
    case 3:
        return new Pikachu(lvl, pos, child);
    case 4:
        return new Raikou(lvl, pos, child);
    case 5:
        return new Diglet(lvl, pos, child);
    case 6:
        return new Groudon(lvl, pos, child);
    case 7:
        return new Squirtle(lvl, pos, child);
    case 8:
        return new Gyarados(lvl, pos, child);
    case 9:
        return new Glaceon(lvl, pos, child);
    case 10:
        return new Articuno(lvl, pos, child);
    default:
        return new Engimon(lvl, pos, child);
    }
}