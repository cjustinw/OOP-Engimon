#include "Player.hpp"
#include <iostream>

using namespace std;

void Player::move(char chr)
{
    if (chr == 'w')
    {
        position.addY();
    }
    else if (chr == 'a')
    {
        position.subX();
    }
    else if (chr == 's')
    {
        position.subY();
    }
    else if (chr == 'd')
    {
        position.addX();
    }
    else
    {
        // throw error
    }
} // Bergerak ke satu petak ke kiri, kanan, atas, atau bawah

void Player::showEngimon(Engimon const &engimonList)
{
    // engimonList.showAll();
}

// Menampilkan list engimon yang dimiliki
void Player::profileEngimon(Engimon engimon);
/* Menampilkan data lengkap suatu engimon (setiap atribut kelas)
    Juga harus menampilkan nama parent beserta spesies mereka */
void Player::activeEngimon();
// Mengecek dan mengganti active engimon
void Player::showSkillItem(Inventory const &inventory);
// Menampilkan list skill item yang dimiliki
void Player::useSkillItem(Inventory item);
// Menggunakan skill item pada suatu engimon
void Player::breed(Engimon breedA, Engimon breedB);
// Melaksanakan breeding antara 2 engimon
void Player::battle(Engimon enemy);
/* Melakukan battle dengan suatu engimon yang berada didekatnya
(adjacent tiles) yaitu satu petak di sebelah kiri, kanan, atas, dan
bawah. */
void Player::printMenu()
{
    cout << "==================================================================" << endl
         << "|| Welcome Player ! Type the menu below :                       ||" << endl
         << "==================================================================" << endl
         << "|| move <w, a, s, d> : Bergerak 1 arah                                 ||" << endl
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
// Mencetak menu pilihan karakter