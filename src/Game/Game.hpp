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
        /* Constructor */
        Game();

        /* Destructor */
        ~Game();

        /* Getter */
        bool getStatus();

        /* Game start */
        void startGame();
        void createWildEngimon();

        /* Movement */
        void movePlayer(string option);
        void moveWildEngimon();

        /* Other Methods */
        void printMenu();
        void playerOption();
        
};

#endif 