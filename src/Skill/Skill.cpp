#include "Skill.hpp"

Skill::Skill()
{
    item = false;
    numOfItem = 0;
}

Skill::~Skill()
{
    
}

string Skill::getSkillName() const
{
    return name;
}

int Skill::getSkillId() const
{
    return id;
}

int Skill::getSkillDamage() const
{
    return basePower * masteryLevel;
}

int Skill::getNumOfItem() const
{
    return numOfItem;
}

int Skill::getMasteryLevel() const 
{
    return masteryLevel;
}

vector<Element*> Skill::getPrereqElmt() const
{
    return prereqElmt;
}

void Skill::setItemStatus(bool status)
{
    item = status;
    numOfItem = 1;
}

void Skill::addSkill()
{
    if(!item)
    {
        //throw
    }
    numOfItem++;
}

void Skill::useSkill()
{
    if(!item)
    {
        //throw
    }
    numOfItem--;
}

void Skill::setMasteryLevel(int lvl)
{
    masteryLevel = lvl;
}

bool Skill::operator==(Skill& other)
{
    return (this == &other);
}

/* Unique */

BlastBurn::BlastBurn() : Skill()
{
    id = 1;
    name = "Blast Burn";
    basePower = 100;
    masteryLevel = 1;
    prereqElmt.push_back(new Fire());
}

Eruption::Eruption() : Skill()
{
    id = 2;
    name = "Eruption";
    basePower = 200;
    masteryLevel = 1;
    prereqElmt.push_back(new Fire());
}

ThunderBolt::ThunderBolt() : Skill()
{
    id = 3;
    name = "Thunder Bolt";
    basePower = 110;
    masteryLevel = 1;
    prereqElmt.push_back(new Electric());
}

Catastropika::Catastropika() : Skill()
{
    id = 4;
    name = "Catastropika";
    basePower = 210;
    masteryLevel = 1;
    prereqElmt.push_back(new Electric());
}

Dig::Dig() : Skill()
{
    id = 5;
    name = "Dig";
    basePower = 80;
    masteryLevel = 1;
    prereqElmt.push_back(new Ground());
}

Earthquake::Earthquake() : Skill()
{
    id = 6;
    name = "Earthquake";
    basePower = 100;
    masteryLevel = 1;
    prereqElmt.push_back(new Ground());
}

WaterGun::WaterGun() : Skill()
{
    id = 7;
    name = "Water Gun";
    basePower = 100;
    masteryLevel = 1;
    prereqElmt.push_back(new Water());
}

OceanicOperetta::OceanicOperetta() : Skill()
{
    id = 8;
    name = "Oceanic Operetta";
    basePower = 195;
    masteryLevel = 1;
    prereqElmt.push_back(new Water());
}

FreezeShock::FreezeShock() : Skill()
{
    id = 9;
    name = "Freeze Shock";
    basePower = 110;
    masteryLevel = 1;
    prereqElmt.push_back(new Ice());
}

IceBurn::IceBurn() : Skill()
{
    id = 10;
    name = "Ice Burn";
    basePower = 210;
    masteryLevel = 1;
    prereqElmt.push_back(new Ice());
}

Charge::Charge() : Skill()
{
    id = 11;
    name = "Charge";
    basePower = 100;
    masteryLevel = 1;
    prereqElmt.push_back(new Electric());
}

Mist::Mist() : Skill()
{
    id = 12;
    name = "Mist";
    basePower = 130;
    masteryLevel = 1;
    prereqElmt.push_back(new Water());
}

MudShot::MudShot() : Skill()
{
    id = 13;
    name = "Mud Shot";
    basePower = 90;
    masteryLevel = 1;
    prereqElmt.push_back(new Ground());
}

/* Fire Type */

Ember::Ember() : Skill()
{
    id = 14;
    name = "Ember";
    basePower = 40;
    masteryLevel = 1;
    prereqElmt.push_back(new Fire());
    prereqElmt.push_back(new Electric());
}

FireBlast::FireBlast() : Skill()
{
    id = 15;
    name = "Fire Blast";
    basePower = 110;
    masteryLevel = 1;
    prereqElmt.push_back(new Fire());
}

FireFang::FireFang() : Skill()
{
    id = 16;
    name = "Fire Fang";
    basePower = 65;
    masteryLevel = 1;
    prereqElmt.push_back(new Fire());
}

/* Electric Type */

ElectroBall::ElectroBall() : Skill()
{
    id = 17;
    name = "Electro Ball";
    basePower = 100;
    masteryLevel = 1;
    prereqElmt.push_back(new Electric());
    prereqElmt.push_back(new Fire());
}

ThunderShock::ThunderShock() : Skill()
{
    id = 18;
    name = "Thunder Shock";
    basePower = 40;
    masteryLevel = 1;
    prereqElmt.push_back(new Electric());
}

VoltTackle::VoltTackle() : Skill()
{
    id = 19;
    name = "Volt Tackle";
    basePower = 120;
    masteryLevel = 1;
    prereqElmt.push_back(new Electric());
}

/* Ground Type */

BoneRush::BoneRush() : Skill()
{
    id = 20;
    name = "Bone Rush";
    basePower = 50;
    masteryLevel = 1;
    prereqElmt.push_back(new Ground());
}

Buldoze::Buldoze() : Skill()
{
    id = 21;
    name = "Buldoze";
    basePower = 90;
    masteryLevel = 1;
    prereqElmt.push_back(new Ground());
}

SandAttack::SandAttack() : Skill()
{
    id = 22;
    name = "Sand Attack";
    basePower = 100;
    masteryLevel = 1;
    prereqElmt.push_back(new Ground());
}

/* Water Type */

HydroCannon::HydroCannon() : Skill()
{
    id = 23;
    name = "Hydro Cannon";
    basePower = 150;
    masteryLevel = 1;
    prereqElmt.push_back(new Water());
    prereqElmt.push_back(new Ice());
}

WaterSpout::WaterSpout() : Skill()
{
    id = 24;
    name = "Water Spout";
    basePower = 150;
    masteryLevel = 1;
    prereqElmt.push_back(new Water());
}

WaterPulse::WaterPulse() : Skill()
{
    id = 25;
    name = "Water Pulse";
    basePower = 60;
    masteryLevel = 1;
    prereqElmt.push_back(new Water());
}

/* Ice Type */

IceHammer::IceHammer() : Skill()
{
    id = 26;
    name = "Ice Hammer";
    basePower = 100;
    masteryLevel = 1;
    prereqElmt.push_back(new Ice());
}

IceShock::IceShock() : Skill()
{
    id = 27;
    name = "Ice Shock";
    basePower = 50;
    masteryLevel = 1;
    prereqElmt.push_back(new Ice());
    prereqElmt.push_back(new Water());
}

FrostBreath::FrostBreath() : Skill()
{
    id = 28;
    name = "Frost Breath";
    basePower = 80;
    masteryLevel = 1;
    prereqElmt.push_back(new Ice());
    prereqElmt.push_back(new Water());
}

Skill* CreateSkill(int ID)
{
    switch (ID)
    {
    case 14:
        return new Ember();
    case 15:
        return new FireBlast();
    case 16:
        return new FireFang();
    case 17:
        return new ElectroBall();
    case 18:
        return new ThunderShock();
    case 19:
        return new VoltTackle();
    case 20:
        return new BoneRush();
    case 21:
        return new Buldoze();
    case 22:
        return new SandAttack();
    case 23:
        return new HydroCannon();
    case 24:
        return new WaterSpout();
    case 25:
        return new WaterPulse();
    case 26:
        return new IceHammer();
    case 27:
        return new IceShock();
    case 28:
        return new FrostBreath();
    default:
        return new Skill();
    }
}


Skill* CreateSkillItem(int ID)
{
    if( ID == 14)
    {
        Skill* skill = new Ember();
        skill->setItemStatus(true);
        return skill;
    }
    else if( ID == 15)
    {
        Skill* skill = new FireBlast();
        skill->setItemStatus(true);
        return skill;
    }
    else if( ID == 16)
    {
        Skill* skill = new FireFang();
        skill->setItemStatus(true);
        return skill;
    }
    else if( ID == 17)
    {
        Skill* skill = new ElectroBall();
        skill->setItemStatus(true);
        return skill;
    }
    else if( ID == 18)
    {
        Skill* skill = new ThunderShock();
        skill->setItemStatus(true);
        return skill;
    }
    else if( ID == 19)
    {
        Skill* skill = new VoltTackle();
        skill->setItemStatus(true);
        return skill;
    }
    else if( ID == 20)
    {
        Skill* skill = new BoneRush();
        skill->setItemStatus(true);
        return skill;
    }
    else if( ID == 21)
    {
        Skill* skill = new Buldoze();
        skill->setItemStatus(true);
        return skill;
    }
    else if( ID == 22)
    {
        Skill* skill = new SandAttack();
        skill->setItemStatus(true);
        return skill;
    }
    else if( ID == 23)
    {
        Skill* skill = new HydroCannon();
        skill->setItemStatus(true);
        return skill;
    }
    else if( ID == 24)
    {
        Skill* skill = new WaterSpout();
        skill->setItemStatus(true);
        return skill;
    }
    else if( ID == 25)
    {
        Skill* skill = new WaterPulse();
        skill->setItemStatus(true);
        return skill;
    }
    else if( ID == 26)
    {
        Skill*skill = new IceHammer();
        skill->setItemStatus(true);
        return skill;
    }
    else if( ID == 27)
    {
        Skill* skill = new IceShock();
        skill->setItemStatus(true);
        return skill;
    }
    else if( ID == 28)
    {
        Skill* skill = new FrostBreath();
        skill->setItemStatus(true);
        return skill;
    }
    else
    {
        return new Skill();
    }
}

Skill* GetRandomSkillItem(vector<Element*> element)
{
    srand(time(0));
    int random;
    if(element.size() == 1)
    {
        if(element[0]->getElmt() == FIRE)
        {
            random = rand() % (17 - 14) + 14;
        }
        else if(element[0]->getElmt() == ELECTRIC)
        {
            random = rand() % (20 - 17) + 17;
        }
        else if(element[0]->getElmt() == GROUND)
        {
            random = rand() % (23 - 20) + 20;
        }
        else if(element[0]->getElmt() == WATER)
        {
            random = rand() % (26 - 23) + 23;
        }
        else if(element[0]->getElmt() == ICE)
        {
            random = rand() % (29 - 26) + 26;
        }
    }
    else
    {
        if(element[0]->getElmt() == FIRE && element[1]->getElmt() == ELECTRIC)
        {
            random = rand() % (20 - 14) + 14;
        }
        else if(element[0]->getElmt() == WATER && element[1]->getElmt() == ICE)
        {
           random = rand() % (29 - 23) + 23;
        }
        else if(element[0]->getElmt() == WATER && element[1]->getElmt() == GROUND)
        {
            random = rand() % (26 - 20) + 20;
        }
    }
    return CreateSkillItem(random);
}