#ifndef __SKILL_HPP__
#define __SKILL_HPP__

#include<string>
#include<vector>
#include"Element.hpp"
using namespace std;

class Skill{
public:
    Skill();
    Skill(int, int, Element);
    ~Skill();
    int getBasePower();
    
protected:
    int basePower;
    int masteryLevel;
    vector<Element*> prereqElmt;
};

class skillItem{
public:
    skillItem();
    skillItem(int);
    virtual void learn();
    int getJumlahSkill();
    void useSkill();
protected:
    int jumlah;
    
};

class Blaze : public Skill{
public:
    Blaze();
};

class innerFocus : public Skill{
public:
    innerFocus();
};

class lightningRod : public Skill{
public:
    lightningRod();
};

class Pressure : public Skill{
public:
    Pressure();
};

class sandForce : public Skill{
public:
    sandForce();
};

class Drought : public Skill{
public:
    Drought();
}

class rainDish : public Skill{
public:
    rainDish();
}

class Moxie : public Skill{
public:
    Moxie();
}

class iceBody : public Skill{
public:
    iceBody();
}

class snowCloak : public Skill{
public:
    snowCloak();
}

class BlazeSkill : public Skill, public skillItem{
public:
    BlazeSkill();
    learn();
};

class innerFocusSkill : public Skill, public skillItem{
public:
    innerFocusSkill();
    learn();
};

class lightningRodSkill : public Skill, public skillItem{
public:
    lightningRodSkill();
    learn();
};

class PressureSkill : public Skill, public skillItem{
public:
    PressureSkill();
    learn();
};

class sandForceSkill : public Skill, public skillItem{
public:
    sandForceSkill();
    learn();
};

class DroughtSkill : public Skill, public skillItem{
public:
    DroughtSkill();
    learn();
}

class rainDishSkill : public Skill, public skillItem{
public:
    rainDishSkill();
    learn();
}

class MoxieSkill : public Skill, public skillItem{
public:
    MoxieSkill();
    learn();
}

class iceBodySkill : public Skill, public skillItem{
public:
    iceBodySkill();
    learn();
}

class snowCloakSkill : public Skill, public skillItem{
public:
    learn();
    snowCloakSkill();
}

#endif
