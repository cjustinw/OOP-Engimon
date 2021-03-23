#include "Skill.hpp"
#include "../Engimon/Engimon.hpp"

int main()
{
    Point P(1,1);
    Charmander* C = new Charmander(1, P, false);
    
    Skill* S;
    S = CreateSkillItem(12);
    Skill* S1;
    S1 = CreateSkillItem(12);
    // Skill* S;
    // S = CreateSkillItem(12);
    // Skill* S;
    // S = CreateSkillItem(12);
    // cout << S->getSkillName() << endl;
    C->learnSkill(S);
    C->learnSkill(S1);
    C->showDescription();
    delete C;
    delete S;
    return 0;
}

//g++ -o driver.exe driver.cpp Skill.cpp ../Engimon/Engimon.cpp ../Point/Point.cpp ../Element/Fire.cpp ../Element/Water.cpp ../Element/Electric.cpp ../Element/Ground.cpp ../Element/Ice.cpp