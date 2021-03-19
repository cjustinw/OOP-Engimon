#include "Game.hpp"

Game::Game()
{
    this->player = new Player();
    this->map = new Map(this->player->getPlayerPosition());
    this->status = true;
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