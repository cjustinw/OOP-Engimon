#ifndef _SKILL_HPP_
#define _SKILL_HPP_

#include <string>
#include <vector>
#include "../Element/Element.hpp"
#include "../Element/Electric.hpp"
#include "../Element/Fire.hpp"
#include "../Element/Water.hpp"
#include "../Element/Ground.hpp"
#include "../Element/Ice.hpp"

using namespace std;

class Skill
{
    protected:
        int id;
        string name;
        int basePower;
        int masteryLevel;
        bool item;
        int numOfItem;
        vector<Element*> prereqElmt;

    public:
        /* Constructor */
        Skill();

        /* Destructor */
        ~Skill();

        /* Getter */
        string getSkillName() const;
        int getSkillId() const;
        int getSkillDamage() const;
        vector<Element*> getPrereqElmt() const;

        /* Setter */
        void setItemStatus(bool status);
        void addSkill();
        void useSkill();

        /* Other method */
        // void learn(Engimon& E);
};

/* Unique */
class BlastBurn : public Skill
{
    public:
        BlastBurn();
};

class Eruption : public Skill
{
    public:
        Eruption();
};

class ThunderBolt : public Skill
{
    public:
        ThunderBolt();
};

class Catastropika : public Skill
{
    public:
        Catastropika();
};

class Dig : public Skill
{
    public:
        Dig();
};

class Earthquake : public Skill
{
    public:
        Earthquake();
};

class WaterGun : public Skill
{
    public:
        WaterGun();
};

class OceanicOperetta : public Skill
{
    public:
        OceanicOperetta();
};

class FreezeShock : public Skill
{
    public:
        FreezeShock();
};

class IceBurn : public Skill
{
    public:
        IceBurn();
};

class Charge : public Skill
{
    public:
        Charge();
};

class Mist : public Skill
{
    public:
        Mist();
};

class MudShot : public Skill
{
    public:
        MudShot();
};



/* Fire Type */

class Ember : public Skill
{
    public:
        Ember();
};

class FireBlast : public Skill
{
    public:
        FireBlast();
};

class FireFang : public Skill
{
    public:
        FireFang();
};

/* Electric Type */

class ElectroBall : public Skill
{
    public:
        ElectroBall();
};

class ThunderShock : public Skill
{
    public:
        ThunderShock();
};

class VoltTackle : public Skill
{
    public:
        VoltTackle();
};

/* Ground Type */

class BoneRush : public Skill
{
    public:
        BoneRush();
};

class Buldoze : public Skill
{
    public:
        Buldoze();
};

class SandAttack : public Skill
{
    public:
        SandAttack();
};

/* Water Type */

class HydroCannon : public Skill
{
    public:
        HydroCannon();
};

class WaterSpout : public Skill
{
    public:
        WaterSpout();
};

class WaterPulse : public Skill
{
    public:
        WaterPulse();
};

/* Ice Type */

class IceHammer : public Skill
{
    public:
        IceHammer();
};

class IceShock : public Skill
{
    public:
        IceShock();
};

class FrostBreath : public Skill
{
    public:
        FrostBreath();
};

Skill* CreateSkill(int ID);

Skill* CreateSkillItem(int ID);

Skill* RandomSkillItem(ElmtType);


#endif
