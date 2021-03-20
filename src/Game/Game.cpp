#include "Game.hpp"
#include "../Map/MapLoader.hpp"

Game::Game()
{
    MapLoader mapLoader;
    this->player = new Player();
    this->map = mapLoader.load();
    this->status = true;
    this->createWildEngimon();
}

Game::~Game()
{

}

bool Game::getStatus()
{
    return this->status;
}

void Game::printMenu()
{
    cout << "==================================================================" << endl
         << "|| Welcome Player ! Type the menu below :                       ||" << endl
         << "==================================================================" << endl
         << "|| move <w, a, s, d> : Bergerak 1 arah                          ||" << endl
         << "|| show engimon : Menampilkan engimon yang dimiliki             ||" << endl
         << "|| profile engimon <nama engimon> : Menampilkan profile engimon ||" << endl
         << "|| active engimon <name engimon> : Menggunakan engimon          ||" << endl
         << "|| show skill item : Menampilkan skill item                     ||" << endl
         << "|| use skill item <nama skill item> : Menggunakan skill item    ||" << endl
         << "|| breed <engimon1> <engimon2> : Melakukan breeding Engimon     ||" << endl
         << "|| battle : Melakukan battle                                    ||" << endl
         << "==================================================================" << endl;
    // get input
}

void Game::playerOption()
{
    this->player->getPlayerPosition().printPoint();
    this->map->view();
    string option;
    cin >> option;
    if(option == "w" || option == "a" || option == "s" || option == "d")
    {
        this->map->setPlayerPosition(this->player->getPlayerPosition(), option);
        this->player->move(option);
    }
    else if (option == "quit")
    {
        this->status = false;
    }
}

void Game::createWildEngimon()
{
    for(int i = 0; i < 10; i++)
    {
        Point Position;
        do{
            Position.setX(rand() % map->getLength() + 1);
            Position.setY(rand() % map->getWidth() + 1);
        } while (!map->isPositionValid(Position));

        int level = rand() % 5 + 1;
        int random = rand() % 2 + 1;

        wildEngimon.push_back(CreateEngimon(random, level, Position, false));

        if(wildEngimon.back()->getElement().size() == 1)
        {
            switch (wildEngimon.back()->getElement()[0]->getElmt())
            {
            case FIRE:
                map->at(Position).setObject('f');
                break;
            case ELECTRIC:
                map->at(Position).setObject('e');
                break; 
            case WATER:
                map->at(Position).setObject('w');
                break;
            case GROUND:
                map->at(Position).setObject('g');
                break; 
            case ICE:
                map->at(Position).setObject('i');
                break;
            default:
                break;
            }
        }
    }
}