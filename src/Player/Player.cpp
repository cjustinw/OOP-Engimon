#include "Player.hpp"
#include <iostream>

using namespace std;

Player::Player()
{
    this->position.setX(1);
    this->position.setY(1);
}

Player::~Player()
{

}

void Player::move(string chr)
{
    if (chr == "w")
    {
        position.addY();
    }
    else if (chr == "a")
    {
        position.subX();
    }
    else if (chr == "s")
    {
        position.subY();
    }
    else if (chr == "d")
    {
        position.addX();
    }
    else
    {
        // throw error
    }
} // Bergerak ke satu petak ke kiri, kanan, atas, atau bawah

Point Player::getPlayerPosition()
{
    return this->position;
}
/**

void Player::showEngimon(Engimon const &engimonList)
{
    // engimonList.showAll();
}

// Menampilkan list engimon yang dimiliki
void Player::profileEngimon(Engimon engimon);
/* Menampilkan data lengkap suatu engimon (setiap atribut kelas)
    Juga harus menampilkan nama parent beserta spesies mereka 
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
bawah. 

*/





// Mencetak menu pilihan karakter