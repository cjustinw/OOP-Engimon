#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <time.h>
#include <vector>
#include "../Engimon/Engimon.hpp"
#include "../Player/Player.hpp"
#include "../Map/Map.hpp"

class Game
{
    private: 
        Player* player;
        Map* map;
        vector<Engimon*> wildEngimon;

        bool status;
    public:
        Game();
        ~Game();

        void createWildEngimon();
        void moveWildEngimon();

        bool getStatus();
        
        void printMenu();
        void playerOption();
        
};

#endif 