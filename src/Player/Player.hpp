#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "../Point/Point.hpp"

class Player
{
public:
    void move(char chr);
    // Bergerak ke satu petak ke kiri, kanan, atas, atau bawah
    void showEngimon(Engimon const &engimonList);
    // Menampilkan list engimon yang dimiliki
    void profileEngimon(Engimon engimon);
    /* Menampilkan data lengkap suatu engimon (setiap atribut kelas)
    Juga harus menampilkan nama parent beserta spesies mereka */
    void activeEngimon();
    // Mengecek dan mengganti active engimon
    void showSkillItem(Inventory const &inventory);
    // Menampilkan list skill item yang dimiliki
    void useSkillItem(Inventory item);
    // Menggunakan skill item pada suatu engimon
    void breed(Engimon breedA, Engimon breedB);
    // Melaksanakan breeding antara 2 engimon
    void battle(Engimon enemy);
    /* Melakukan battle dengan suatu engimon yang berada didekatnya
    (adjacent tiles) yaitu satu petak di sebelah kiri, kanan, atas, dan
    bawah. */
    void printMenu();
    // Mencetak menu pilihan karakter

private:
    Inventory inventory;
    Point position;
    Engimon engimonList[];
    Engimon activeEngimon;
};

#endif