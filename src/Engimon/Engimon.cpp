#include"Engimon.hpp"

/* Engimon */

Engimon::Engimon()
{
    
}

Engimon::Engimon(int lvl, Point pos, bool child)
{
    level = lvl;
    maxSkills = 4;
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

vector<Skill*> Engimon::getSkill() 
{
    return skills;
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
    int sumPower = 0;
    for(int i = 0; i < skills.size(); i++)
    {
        sumPower += skills[i]->getSkillDamage();
    }
    cout << level << " * " << maxAdvantage << " + " << sumPower;
    return this->level * maxAdvantage + sumPower;
}

int Engimon::getID() const
{
    return ID;
}

string Engimon::getParent() const
{
    return parent;
}

int Engimon::getNumOfSkills() const
{
    return skills.size();
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
    cout << getName() << " gains " << exp << " exp!" << endl;
}

void Engimon::levelUp()
{
    int lvl = exp /(level*100);
    if(lvl > 0)
    {
        level += lvl;
        exp = exp % lvl*100;
        cout << getName() << " now becomes level " << getCurrentLevel() << "!" << endl;
    }

}

void Engimon::learnSkill(Skill* skill)
{
    bool found = false;
    for(int i = 0; i < elements.size(); i++)
    {
        for(int j = 0; j < skill->getPrereqElmt().size(); j++)
        {
            if(elements[i]->getElmt() == skill->getPrereqElmt()[j]->getElmt())
            {
                found = true;
                break;
            }
        }
    }
    if(!found)
    {
        throw InvalidInputException();
    }
    for(int i = 0; i < skills.size(); i++)
    {
        if(skills[i]->getSkillId() == skill->getSkillId())
        {
            throw InvalidInputException();
        }
    }
    skill->useSkill();
    skills.push_back(CreateSkill(skill->getSkillId()));
    cout << name << " has learned to use " << skill->getSkillName() << endl;
}

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

void Engimon::removeSkillByIndex(int idx)
{
    skills.erase(skills.begin() + idx);
}

/* Conditional Checking */
bool Engimon::isMaxCumulativeExp()
{
    return cumulativeExp >= MAX_CUMULATIVE_EXP;
}

bool Engimon::isSkillMax()
{
    return getNumOfSkills() >= maxSkills;
}

bool Engimon::isActiveEngimon()
{
    return active;
}

bool Engimon::isChild()
{
    return child;
}

bool Engimon::canBreeding()
{
    return level > 30;
}

bool Engimon::operator==(Engimon& other)
{
    return this == &other;
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
    cout << "   Skills      : " << endl;
    for(int i = 0; i < skills.size(); i++)
    {
        cout << "                 - " << skills[i]->getSkillName() << endl; 
    }
    cout << "   Level       : " << getCurrentLevel() <<endl
         << "   EXP         : " << getCurrentExp() << "/" << level*100 << endl
         << "   Max EXP     : " << cumulativeExp << "/" << MAX_CUMULATIVE_EXP << endl
         << "========================================" << endl;
}       

void Engimon::interact()
{
    cout << "Engimon~~" << endl;
}

Engimon* Engimon::breed(Engimon& other, string name)
{
    Engimon* E;
    vector<Skill*> S;
    Point P(0,0);
    int thisAdvantage = this->getElement()[0]->elementAdvantage(other.getElement()[0]->getElmt());
    int otherAdvantage = other.getElement()[0]->elementAdvantage(this->getElement()[0]->getElmt());
    if(thisAdvantage > otherAdvantage)
    {
        E = CreateEngimon(this->getID(), 30, P, true);
        for(int i = 1; i < skills.size(); i++)
        {
            S.push_back(CreateSkill(skills[i]->getSkillId()));
        }
        sort(S.begin(), S.end(), [](const Skill* S1, const Skill* S2)
        {
            return S1->getMasteryLevel() > S2->getMasteryLevel();
        });
        int i = 0;
        while(!E->isSkillMax() && i < S.size())
        {
            for(int k = 0; k < skills.size(); k++)
            {
                if(S[i]->getSkillId() == skills[k]->getSkillId())
                {
                    int masteryLvl = skills[k]->getMasteryLevel();
                    S[i]->setMasteryLevel(masteryLvl);
                    E->skills.push_back(S[i]);
                    break;
                }
            }
            i++;
        }
    }
    else if(thisAdvantage < otherAdvantage)
    {
        E = CreateEngimon(other.getID(), 30, P, true);
        for(int i = 1; i < other.skills.size(); i++)
        {
            S.push_back(CreateSkill(other.skills[i]->getSkillId()));
        }
        sort(S.begin(), S.end(), [](const Skill* S1, const Skill* S2)
        {
            return S1->getMasteryLevel() > S2->getMasteryLevel();
        });
        int i = 0;
        while(!E->isSkillMax() && i < S.size())
        {
            for(int k = 0; k < other.skills.size(); k++)
            {
                if(S[i]->getSkillId() == other.skills[k]->getSkillId())
                {
                    int masteryLvl = other.skills[k]->getMasteryLevel();
                    S[i]->setMasteryLevel(masteryLvl);
                    E->skills.push_back(S[i]);
                    break;
                }
            }
            i++;
        }
    }
    else
    {
        vector<Skill*> S2;
        if(this->getElement()[0]->getElmt() == other.getElement()[0]->getElmt())
        {
            E = CreateEngimon(this->getID(), 30, P, true);
        }
        else if(this->getElement()[0]->getElmt() == FIRE && other.getElement()[0]->getElmt() == ELECTRIC || this->getElement()[0]->getElmt() == ELECTRIC && other.getElement()[0]->getElmt() == FIRE)
        {
            E = CreateEngimon(7, 30, P, true);
        }
        else if(this->getElement()[0]->getElmt() == WATER && other.getElement()[0]->getElmt() == ICE || this->getElement()[0]->getElmt() == ICE && other.getElement()[0]->getElmt() == WATER)
        {
            E = CreateEngimon(12, 30, P, true);
        }
        else if(this->getElement()[0]->getElmt() == WATER && other.getElement()[0]->getElmt() == GROUND || this->getElement()[0]->getElmt() == GROUND && other.getElement()[0]->getElmt() == WATER)
        {
            E = CreateEngimon(13, 30, P, true);
        }
        for(int i = 1; i < skills.size(); i++)
        {
            S.push_back(CreateSkill(skills[i]->getSkillId()));
        }
        sort(S.begin(), S.end(), [](const Skill* S3, const Skill* S4)
        {
            return S3->getMasteryLevel() > S4->getMasteryLevel();
        });
        for(int i = 1; i < other.skills.size(); i++)
        {
            S2.push_back(CreateSkill(other.skills[i]->getSkillId()));
        }
        sort(S2.begin(), S2.end(), [](const Skill* S3, const Skill* S4)
        {
            return S3->getMasteryLevel() > S4->getMasteryLevel();
        }); 
        int i = 0, j = 0;
        while(!E->isSkillMax() && i < S.size() && j < S2.size())
        {
            if(S[i]->getMasteryLevel() >= S2[j]->getMasteryLevel()) 
            {
                bool found = false;
                for(int k = 0; k < E->skills.size(); k++)
                {
                    if(E->skills[k]->getSkillId() == S[i]->getSkillId())
                    {
                        found = true;
                    }
                }
                if(!found)
                {
                    for(int k = 0; k < skills.size(); k++)
                    {
                        if(S[i]->getSkillId() == skills[k]->getSkillId())
                        {
                            int masteryLvl = skills[k]->getMasteryLevel();
                            if(S[i]->getMasteryLevel() > S2[j]->getMasteryLevel())
                            {
                                S[i]->setMasteryLevel(masteryLvl);
                            }
                            else 
                            {
                                masteryLvl++;
                                S[i]->setMasteryLevel(masteryLvl);
                            }
                            E->skills.push_back(S[i]);
                            break;
                        }
                    }
                }
                i++;
            }
            else if(S[i]->getMasteryLevel() < S2[j]->getMasteryLevel())
            {
                bool found = false;
                for(int k = 0; k < E->skills.size(); k++)
                {
                    if(E->skills[k]->getSkillId() == S2[j]->getSkillId())
                    {
                        found = true;
                    }
                }
                if(!found)
                {
                    for(int k = 0; k < other.skills.size(); k++)
                    {
                        if(S2[j]->getSkillId() == other.skills[k]->getSkillId())
                        {
                            int masteryLvl = other.skills[k]->getMasteryLevel();
                            S2[j]->setMasteryLevel(masteryLvl);
                            E->skills.push_back(S2[j]);
                            break;
                        }
                    }
                    j++;
                }
            } 
        }
        if(!E->isSkillMax())
        {
            if(i < S.size())
            {
                bool found = false;
                for(int k = 0; k < E->skills.size(); k++)
                {
                    if(E->skills[k]->getSkillId() == S[i]->getSkillId())
                    {
                        found = true;
                    }
                }
                if(!found)
                {
                    for(int k = 0; k < skills.size(); k++)
                    {
                        if(S[i]->getSkillId() == skills[k]->getSkillId())
                        {
                            int masteryLvl = skills[k]->getMasteryLevel();
                            S[i]->setMasteryLevel(masteryLvl);
                            E->skills.push_back(S[i]);
                            break;
                        }
                    }
                    i++;
                }
            }
            else if(j < S2.size())
            {
                bool found = false;
                for(int k = 0; k < E->skills.size(); k++)
                {
                    if(E->skills[k]->getSkillId() == S2[j]->getSkillId())
                    {
                        found = true;
                    }
                }
                if(!found)
                {
                    for(int k = 0; k < other.skills.size(); k++)
                    {
                        if(S2[j]->getSkillId() == other.skills[k]->getSkillId())
                        {
                            int masteryLvl = other.skills[k]->getMasteryLevel();
                            S2[j]->setMasteryLevel(masteryLvl);
                            E->skills.push_back(S2[j]);
                            break;
                        }
                    }
                    j++;
                }
            }
        }
    }
    E->setName(name);
    E->setParent(this->getName() + " (" + this->getSpecies() + "), " + other.getName() + " (" + other.getSpecies() + ")");
    this->setLevelAfterBreeding();
    other.setLevelAfterBreeding();
    return E;
}

/* Charmander */
Charmander::Charmander(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 1;
    name = "Charmander";
    species = "Charmander";
    elements.push_back(new Fire());
    skills.push_back(new BlastBurn());
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
    cout << "Charmander: Chaa~ Chaa~ Chaarmander" << endl;
}

/* Entei */
Entei::Entei(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 2;
    name = "Entei";
    species = "Entei";
    elements.push_back(new Fire());
    skills.push_back(new Eruption());
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
    cout << "Entei: Rrrrraaawrrrr~" << endl;
}

/* Pikachu */
Pikachu::Pikachu(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 3;
    name = "Pikachu";
    species = "Pikachu";
    elements.push_back(new Electric());
    skills.push_back(new ThunderBolt());
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
    cout << "Pikachu: Pika~ Pika~" << endl;
}

/* Raikou */
Raikou::Raikou(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 4;
    name = "Raikou";
    species = "Raikou";
    elements.push_back(new Electric());
    skills.push_back(new Catastropika());
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
    cout << "Raikou: Rrrrrooowrrrr~" << endl;
}

/* Diglet */
Diglet::Diglet(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 5;
    name = "Diglet";
    species = "Diglet";
    elements.push_back(new Ground());
    skills.push_back(new Dig());
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
    cout << "Diglet: Didididi~ Diglet" << endl;
}

/* Groudon */
Groudon::Groudon(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 6;
    name = "Groudon";
    species = "Groudon";
    elements.push_back(new Ground());
    skills.push_back(new Earthquake());
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
    cout << "Groudon: Rrrrrraaaaaaaa~" << endl;
}

/* Rotom */
Rotom::Rotom(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 7;
    name = "Rotom";
    species = "Rotom";
    elements.push_back(new Fire());
    elements.push_back(new Electric());
    skills.push_back(new Charge());
}

void Rotom::operator=(const Rotom& other)
 {
    this->operator=(other);
    ID = other.getID();
    name = other.getName();
    species = other.getSpecies();
    elements.push_back(other.getElement()[0]);
 }

Rotom::~Rotom()
{

}

void Rotom::interact()
{
    cout << "Rotom: Rotom~" << endl;
}

/* Squirtle */
Squirtle::Squirtle(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 8;
    name = "Squirtle";
    species = "Squirtle";
    elements.push_back(new Water());
    skills.push_back(new WaterGun());
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
    cout << "Squirtle: Squirtle~" << endl;
}

/* Gyarados */
Gyarados::Gyarados(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 9;
    name = "Gyarados";
    species = "Gyarados";
    elements.push_back(new Water());
    skills.push_back(new OceanicOperetta());
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
    cout << "Gyarados: Groudon: Rrrrrroooooooo~" << endl;
}

/* Glaceon */
Glaceon::Glaceon(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 10;
    name = "Glaceon";
    species = "Glaceon";
    elements.push_back(new Ice());
    skills.push_back(new FreezeShock());
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
    cout << "Glaceon: Glaceon~" << endl;
}

/* Articuno */
Articuno::Articuno(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 11;
    name = "Articuno";
    species = "Articuno";
    elements.push_back(new Ice());
    skills.push_back(new IceBurn());
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
    cout << "Articuno: Rrrrreeee~" << endl;
}

/* Lapras */
Lapras::Lapras(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 12;
    name = "Lapras";
    species = "Lapras";
    elements.push_back(new Water());
    elements.push_back(new Ice());
    skills.push_back(new Mist());
}

void Lapras::operator=(const Lapras& other)
 {
    this->operator=(other);
    ID = other.getID();
    name = other.getName();
    species = other.getSpecies();
    elements.push_back(other.getElement()[0]);
 }

Lapras::~Lapras()
{

}

void Lapras::interact()
{
    cout << "Lapras: Aaaaarrrr~" << endl;
}

/* Swampert */
Swampert::Swampert(int lvl, Point pos, bool child) : Engimon(lvl, pos, child)
{
    ID = 13;
    name = "Swampert";
    species = "Swampert";
    elements.push_back(new Water());
    elements.push_back(new Ground());
    skills.push_back(new MudShot());
}

void Swampert::operator=(const Swampert& other)
 {
    this->operator=(other);
    ID = other.getID();
    name = other.getName();
    species = other.getSpecies();
    elements.push_back(other.getElement()[0]);
 }

Swampert::~Swampert()
{

}

void Swampert::interact()
{
    cout << "Swampert: Swampert~" << endl;
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
        return new Rotom(lvl, pos, child);
    case 8:
        return new Squirtle(lvl, pos, child);
    case 9:
        return new Gyarados(lvl, pos, child);
    case 10:
        return new Glaceon(lvl, pos, child);
    case 11:
        return new Articuno(lvl, pos, child);
    case 12:
        return new Lapras(lvl, pos, child);
    case 13:
        return new Swampert(lvl, pos, child);
    default:
        return new Engimon(lvl, pos, child);
    }
}