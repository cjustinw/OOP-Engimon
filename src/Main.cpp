#include "Game/Game.hpp"

int main()
{
    Game* game = new Game();
    game->printMenu();
    while(game->getStatus())
    {
        game->playerOption();
    }
    return 0;
}

//g++ -o Main.exe Main.cpp Game/Game.cpp Map/Map.cpp Map/Cell.cpp Player/Player.cpp Point/Point.cpp Map/MapLoader.cpp