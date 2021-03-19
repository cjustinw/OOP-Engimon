#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "../Player/Player.hpp"
#include "../Map/Map.hpp"

class Game
{
    private: 
        Player* player;
        Map* map;
        bool status;
    public:
        Game();
        ~Game();

        bool getStatus();
        
        void printMenu();
        void playerOption();
        
};

#endif 