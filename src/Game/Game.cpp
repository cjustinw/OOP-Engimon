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
    delete player;
    delete map;
}

bool Game::getStatus()
{
    return this->status;
}

void Game::startGame()
{
    cout << "Choose your first Engimon!" << endl
         << "   - Entei" << endl 
         << "   - Raikou" << endl;

    string option;
    cout << endl << "Player input: "; cin >> option;
    Point P(2,1);
    map->at(P).setObject('X');
    if(option == "Entei")
    {
        player->addEngimon(*CreateEngimon(2, 5, P, false));
        player->setActiveEngimon(0);
    }
    else if(option == "Raikou")
    {
        player->addEngimon(*CreateEngimon(4, 5, P, false));
        player->setActiveEngimon(0);
    }   
    else 
    {
        //throw
    }
    string engimonName;
    cout << endl << "Give your " << player->getActiveEngimon()->getName() << " a name: "; cin >> engimonName;
    player->setEngimonName(0, engimonName);
}

void Game::printMenu()
{
    cout << "==================================================================" << endl
         << "|| Welcome Player ! Type the menu below :                       ||" << endl
         << "==================================================================" << endl
         << "|| <w, a, s, d> : Bergerak 1 arah                               ||" << endl
         << "|| \"show engimon\" : Menampilkan engimon yang dimiliki           ||" << endl
         << "|| \"profile engimon\" : Menampilkan profile engimon              ||" << endl
         << "|| \"set active engimon\" : Menggunakan engimon                   ||" << endl
         << "|| \"show skill item\" : Menampilkan skill item                   ||" << endl
         << "|| \"use skill item\" : Menggunakan skill item                    ||" << endl
         << "|| \"breed\" : Melakukan breeding Engimon                         ||" << endl
         << "==================================================================" << endl;
    
    cout << endl << "Map:" << endl;
    map->view();
    cout << "Your position: (" << player->getPlayerPosition().getX() << "," << player->getPlayerPosition().getY() << ")"<< endl;
    cout << "Active Engimon: " << player->getActiveEngimon()->getName() <<  " (" << player->getActiveEngimon()->getSpecies() <<") "<< endl;
}

void Game::playerOption()
{
    string option;
    cout << endl << "Player input: "; getline(cin, option);
    cout << endl;

    if(option == "w" || option == "a" || option == "s" || option == "d")
    {
       movePlayer(option);
    }
    else if(option.find("show engimon") != string::npos)
    {
        player->showAllEngimon();
        cout << endl;
        system("pause");
    }
    else if(option.find("profile engimon") != string::npos)
    {
        player->showAllEngimon();
        int num;
        cout << endl << "Input number: "; cin >> num;
        cout << endl;
        player->showEngimonDescription(num-1);
        cout << endl;
        system("pause");
    }
    else if(option.find("set active engimon") != string::npos)
    {
        player->showAllEngimon();
        int num;
        cout << endl << "Input number: "; cin >> num;
        cout << endl;
        player->setActiveEngimon(num-1);
        cout << "Your active engimon changes to " << player->getActiveEngimon()->getName()  <<  " (" << player->getActiveEngimon()->getSpecies() <<") "<< endl;
        cout << endl;
        system("pause");
    }
    else if(option.find("show skill item") != string::npos)
    {
        player->showAllSkillItem();
        cout << endl;
        system("pause");
    }
    else if(option.find("use skill item") != string::npos)
    {
        player->showAllSkillItem();
        int num1, num2;
        cout << endl << "Select skill item: "; cin >> num1;
        Skill* S = player->getSkillByIndex(num1-1);
        cout << endl;
        player->showEngimonBySkillItem(*player->getSkillByIndex(num1-1));
        cout << endl  <<"Select engimon: "; cin >> num2;
        Engimon* E = player->getEngimonByIndex(num2-1);
        player->useSkillItem(*S, *E);
        cout << endl;
        system("pause");
    }
    else if(option.find("breed") != string::npos)
    {
        player->showAllEngimon();
        int num1, num2;
        string name;
        cout << endl << "Select engimon 1 to breed: "; cin >> num1;
        cout << endl << "Select engimon 2 to breed: "; cin >> num2;
        cout << endl << "Select engimon chile name: "; cin >> name;
        Engimon* E = player->getEngimonByIndex(num1-1)->breed(*player->getEngimonByIndex(num2-1), name);
        cout << endl << "Congrats! " << name << " is born!";
        cout << endl << name << " will be added to your inventory!";
        player->addEngimon(*E);
        cout << endl;
        system("pause");
    }
    else if (option == "quit")
    {
        this->status = false;
    }
    
    system("cls");
}

void Game::createWildEngimon()
{
    srand(time(0));

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
            random = rand() % (8 - 1) + 1;
        }
        else
        {
            random = rand() % (14 - 8) + 8;
        }

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
        else
        {
            if(wildEngimon.back()->getElement()[0]->getElmt() == FIRE && wildEngimon.back()->getElement()[1]->getElmt() == ELECTRIC)
            {
                if(level > 5){
                    map->at(Position).setObject('L');
                }
                else{
                    map->at(Position).setObject('l');
                }
            }
            else if(wildEngimon.back()->getElement()[0]->getElmt() == WATER && wildEngimon.back()->getElement()[1]->getElmt() == ICE)
            {
                if(level > 5){
                    map->at(Position).setObject('S');
                }
                else{
                    map->at(Position).setObject('s');
                }
            }
            else if(wildEngimon.back()->getElement()[0]->getElmt() == WATER && wildEngimon.back()->getElement()[1]->getElmt() == GROUND)
            {
                if(level > 5){
                    map->at(Position).setObject('N');
                }
                else{
                    map->at(Position).setObject('n');
                }
            }

        }
    }
}

void Game::movePlayer(string option)
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
        bool winStat = true;
        for(int i = 0; i < wildEngimon.size(); i++)
        {
            if(wildEngimon[i]->getPosition() == P)
            {
                battle(*player, *wildEngimon[i], winStat);
                system("pause");
            }
        }
        if(winStat)
        {
            map->at(P).setObject('P');
            map->at(player->getPlayerPosition()).setObject('X');

            if(!(player->getActiveEngimon()->getPosition() == P))
            {
                if(map->at(player->getActiveEngimon()->getPosition()).getType() == GRASS)
                {
                    map->at(player->getActiveEngimon()->getPosition()).setObject('-');
                }
                else
                {
                    map->at(player->getActiveEngimon()->getPosition()).setObject('o');
                }            
            }
            player->getActiveEngimon()->setPosition(player->getPlayerPosition());
            player->move(option);
            moveWildEngimon();
        }
    }
}

void Game::moveWildEngimon()
{
    srand(time(0));

    for(int i = 0; i < wildEngimon.size(); i++)
    {
        bool isGrass, found = false;
        Point Position;
        int j = 0;
        while(!found && j < 20)
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
            
            if( Position.getX() > 0 && Position.getX() < map->getLength() && Position.getY() > 0 && Position.getY() < map->getWidth())
            {
                // cout << "test5" << endl;
                if(isGrass)
                {
                    if(wildEngimon[i]->getElement().size() > 1)
                    {
                        if(wildEngimon[i]->getElement()[0]->getElmt() == WATER && wildEngimon[i]->getElement()[1]->getElmt() == GROUND)
                        {
                            if(map->at(Position).getObject() == 'o' || map->at(Position).getObject() == 'P')
                            {
                                found = true;
                            }
                        }
                    }
                    if(map->at(Position).getObject() == '-' || map->at(Position).getObject() == 'P')
                    {
                        found = true;
                    }
                    
                }
                else
                {
                    if(wildEngimon[i]->getElement().size() > 1)
                    {
                        if(wildEngimon[i]->getElement()[0]->getElmt() == WATER && wildEngimon[i]->getElement()[1]->getElmt() == GROUND)
                        {
                            if(map->at(Position).getObject() == '-' || map->at(Position).getObject() == 'P')
                            {
                                found = true;
                            }
                        }
                    }
                    if(map->at(Position).getObject() == 'o' || map->at(Position).getObject() == 'P')
                    {
                        found = true;
                    }
                }
            }
            j++;
        }

        if(found)
        {
            if(!(Position == player->getPlayerPosition()))
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
}

void Game::battle(Player& P, Engimon& E, bool& winStat)
{   
    cout << "Wild " << E.getName() << " appeared!" << endl;

    cout << endl << P.getActiveEngimon()->getName() <<" status: " << endl;

    P.getActiveEngimon()->showDescription();

    cout << endl << E.getName() << " status: " << endl; 

    E.showDescription();

    cout << endl << "Power : level * element advantage + SUM(every skill base power * Mastery Level)" << endl;
    cout << P.getActiveEngimon()->getName() << " Power: ";
    int playerPower = P.getActiveEngimon()->getPower(E);
    cout << " : " << playerPower << endl;
    cout << E.getName() << " Power: ";
    int wildEngimonPower = E.getPower(*P.getActiveEngimon());
    cout << " : " << wildEngimonPower << endl;

    if(playerPower >= wildEngimonPower)
    {
        winStat = true;
        cout << endl << P.getActiveEngimon()->getName() << " wins! " << endl;
        int exp = 20* E.getCurrentLevel();
        P.getActiveEngimon()->expUp(exp);
        P.getActiveEngimon()->levelUp();
        cout << "NUM Inventory: " << P.getNumOfAllItem() << endl;
        if(P.isInventoryFull())
        {
            //throw
        }
        cout << E.getName() << " will be added to your inventory! " << endl;
        P.addEngimon(E);
        if(P.isInventoryFull())
        {
            //throw
        }
        Skill* S = GetRandomSkillItem(E.getElement());
        cout << "You get " << S->getSkillName() << " skill item!" << endl << endl;
        if(P.isSkillItemExist(*S) != NULL)
        {
            P.isSkillItemExist(*S)->addSkill();
            delete S;
        }
        else
        {
            P.addSkillItem(*S);
        }
        auto j = wildEngimon.begin();
        for(int i = 0; i < wildEngimon.size(); i++)
        {
           if(wildEngimon[i]->getPosition() == E.getPosition())
           {
                wildEngimon.erase(j);
                break;
           }
           j++;
        }
    }
    else
    {
        winStat = false;
        cout << endl << P.getActiveEngimon()->getName() << " is defeated! " << endl;
        cout <<P.getActiveEngimon()->getName() << " will be removed from your inventory! " << endl;
        Point Ptmp(player->getActiveEngimon()->getPosition());
        player->removeEngimon(*player->getActiveEngimon());
        if(player->getNumOfEngimon() == 0)
        {
            cout << "You don't have any engimon left!" << endl;
            cout << "Game Over!" << endl << endl;
            status = false;
        }
        else
        {
            player->showAllEngimon();
            int num;
            cout << endl << "Set another active engimon: "; cin >> num;
            cout << endl;
            player->setActiveEngimon(num-1);
            player->getActiveEngimon()->setPosition(Ptmp);
            cout << "Your active engimon changes to " << player->getActiveEngimon()->getName()  <<  " (" << player->getActiveEngimon()->getSpecies() <<") "<< endl;
            cout << endl;
        }
        
    }
}