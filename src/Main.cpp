#include "Game/Game.hpp"

int main()
{
    Game* game = new Game();
    game->startGame();
    while(game->getStatus())
    {
        game->printMenu();
        game->playerOption();
    }
    delete game;
    return 0;
}

//g++ -o Main.exe Main.cpp Game/Game.cpp Map/Map.cpp Map/Cell.cpp Player/Player.cpp Point/Point.cpp Map/MapLoader.cpp Engimon/Engimon.cpp Skill/Skill.cpp Element/Fire.cpp Element/Water.cpp Element/Electric.cpp Element/Ground.cpp Element/Ice.cpp