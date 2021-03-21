#ifndef __SKILL_HPP__
#define __SKILL_HPP__

#include<string>
#include "../Element/Element.hpp"

using namespace std;

class Skill{
public:
    Skill();
    Skill(int, int, Element);
    ~Skill();
    getBasePower()
    
protected:
    int basePower;
    int masteryLevel;
    Element* prereqElmt;
};


#endif
