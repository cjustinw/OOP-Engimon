#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <time.h>
#include <vector>
#include "../Engimon/Engimon.hpp"
#include "../Player/Player.hpp"
#include "../Map/Map.hpp"
#include "../Exception/Exception.hpp"

class Game
{
    private: 
        Player* player;
        Map* map;
        vector<Engimon*> wildEngimon;
        bool status;

        /* Game start */
        void createWildEngimon();

        /* Movement */
        void movePlayer(string option);
        void moveWildEngimon();

        /* Other Methods */
        void battle(Player& P, Engimon& E, bool& winStat);
        void startLogo();
        void gameOverLogo();
  
        /* Player Command */
        void showEngimon();
        void profileEngimon();
        void setActiveEngimon();
        void showSkillItem();
        void useSkillItem();
        void breed();

    public:
        /* Constructor */
        Game();

        /* Destructor */
        ~Game();

        /* Getter */
        bool getStatus();

        /* Game start */
        void startGame();

        /* Game running */
        void runGame();

        /* Other Methods */
        void printMenu();
        void playerOption();

};

#endif 