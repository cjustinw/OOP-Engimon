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
        Point P;
        P.setX(player->getPlayerPosition().getX());
        P.setY(player->getPlayerPosition().getY());
        if (option == "w")
        {    
            P.addY();
        }
        else if (option == "a")
        {
            P.subX();
        }
        else if (option == "s")
        {
            P.subY();
        }
        else if (option == "d")
        {
            P.addX();
        }
        if(P.getX() > 0 && P.getX() < map->getLength() && P.getY() > 0 && P.getY() < map->getWidth())
        {
            if(map->at(P).getObject() != '-' && map->at(P).getObject() != 'o')
            {
                auto j = wildEngimon.begin();
                for(int i = 0; i < wildEngimon.size(); i++)
                {
                    if(wildEngimon[i]->getPosition().getX() == P.getX() && wildEngimon[i]->getPosition().getY() == P.getY())
                    {
                        /* Battle */
                        wildEngimon[i]->showDescription();
                        wildEngimon.erase(j);
                    }
                    j++;
                }

                map->at(P).setObject('P');
                if(map->at(player->getPlayerPosition()).getType() == GRASS)
                {
                    map->at(player->getPlayerPosition()).setObject('-');
                }
                else
                {
                    map->at(player->getPlayerPosition()).setObject('o');
                }
                player->move(option);
            }
            else{
                this->moveWildEngimon();
                if(map->at(P).getObject() != '-')
                {
                    auto j = wildEngimon.begin();
                    for(int i = 0; i < wildEngimon.size(); i++)
                    {
                        if(wildEngimon[i]->getPosition().getX() == P.getX() && wildEngimon[i]->getPosition().getY() == P.getY())
                        {
                            /* Battle */
                            wildEngimon[i]->showDescription();
                            wildEngimon.erase(j);
                        }
                        j++;
                    }
                }
                map->at(P).setObject('P');
                if(map->at(player->getPlayerPosition()).getType() == GRASS)
                {
                    map->at(player->getPlayerPosition()).setObject('-');
                }
                else
                {
                    map->at(player->getPlayerPosition()).setObject('o');
                }
                player->move(option);
            }
        }
    }
    else if (option == "quit")
    {
        this->status = false;
    }
    
}

void Game::createWildEngimon()
{
    srand(time(0));
    /* Buat coba2 dulu, nanti disesuaikan lagi */
    for(int i = 0; i < 20; i++)
    {
        Point Position;
        do{
            Position.setX(rand() % map->getLength() + 1);
            Position.setY(rand() % map->getWidth() + 1);
        } while (!map->isPositionValid(Position));

        int level = rand() % 10 + 1;

        int random;

        if(map->at(Position).getObject() == '-')
        {
            random = rand() % (7 - 1) + 1;
        }
        else
        {
            random = rand() % (11 - 7) + 7;
        }
        // cout << random << endl;
        wildEngimon.push_back(CreateEngimon(random, level, Position, false));
        
        if(wildEngimon.back()->getElement().size() == 1)
        {
            switch (wildEngimon.back()->getElement()[0]->getElmt())
            {
            case FIRE:
                if(level > 5){
                    map->at(Position).setObject('F');
                }
                else{
                    map->at(Position).setObject('f');
                }
                break;
            case ELECTRIC:
                if(level > 5){
                    map->at(Position).setObject('E');
                }
                else{
                    map->at(Position).setObject('e');
                }
                break; 
            case WATER:
                if(level > 5){
                    map->at(Position).setObject('W');
                }
                else{
                    map->at(Position).setObject('w');
                }
                break;
            case GROUND:
                if(level > 5){
                    map->at(Position).setObject('G');
                }
                else{
                    map->at(Position).setObject('g');
                }
                break; 
            case ICE:
                if(level > 5){
                    map->at(Position).setObject('I');
                }
                else{
                    map->at(Position).setObject('i');
                }
                break;
            default:
                break;
            }
        }
    }
}

void Game::moveWildEngimon()
{
    srand(time(0));
    /* Buat coba2 dulu, nanti disesuaikan lagi */
    for(int i = 0; i < wildEngimon.size(); i++)
    {
        bool isGrass, found = false;
        Point Position;
        while(!found)
        {
            Position.setX(wildEngimon[i]->getPosition().getX());
            Position.setY(wildEngimon[i]->getPosition().getY());

            if(map->at(Position).getType() == GRASS)
            {
                isGrass = true;
            }
            else
            {
                isGrass = false;
            }
            
            int option = rand() % 4 + 1;
            switch (option)
            {
            case 1:
                Position.addY();
                break;
            case 2:
                Position.addX();
                break;
            case 3:
                Position.subX();
                break;
            case 4:
                Position.subY();
                break;
            default:
                break;
            }
            
            if(map->isWildEngimonPositionValid(Position, isGrass))
            {
                found = true;
            }
        }

        if(found)
        {
            map->at(Position).setObject(map->at(wildEngimon[i]->getPosition()).getObject());
            if(isGrass)
            {
                map->at(wildEngimon[i]->getPosition()).setObject('-');
            }
            else
            {
                map->at(wildEngimon[i]->getPosition()).setObject('o');
            }
            wildEngimon[i]->setPosition(Position.getX(), Position.getY());
        }
    }
}