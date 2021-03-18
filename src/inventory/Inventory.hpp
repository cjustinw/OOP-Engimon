#ifndef _INVENTORY_HPP_
#define _INVENTORY_HPP_

#include <iostream>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
template<class E, class S>
class Inventory{
	public:
		//Default Constructor: set max_capacity = 100; Neff = 0
		Inventory():Inventory(100){	
            this->Neff = 0;
            this->inventory = new string[this->max_capacity];
            this->Engi = new E[this->Neff];
            int sisa_efektif = this->max_capacity - this->Neff;
            this->Skill = new S[sisa_efektif];

            set_union(begin(this->Engi), end(this->Engi),
                        begin(this->Skill), end(this->Skill),
                        inserter(this->inventory, begin(this->inventory)));

		}
        //User-defined constructor: set kapasitas maksimum sesuai masukan, Neff=0
        Inventory(int _max_capacity): max_capacity(_max_capacity), Neff(0){
            this->inventory = new string[this->max_capacity];
            this->Engi = new E[this->Neff];
            int sisa_efektif = this->max_capacity - this->Neff;            
            this->Skill = new S[sisa_efektif];
            set_union(begin(this->Engi), end(this->Engi),
                        begin(this->Skill), end(this->Skill),
                        inserter(this->inventory, begin(this->inventory)));
        }
        //Copy constructor:mengopi max_capacity, Neff, dan this->inventory
        Inventory(const Inventory& T){
            int i;

            this->max_capacity = T.max_capacity;
            this->Neff = T.Neff;
            this->inventory = new string[this->max_capacity];
            this->Engi = new E[this->Neff];
            int sisa_efektif = this->max_capacity - this->Neff;            
            this->Skill = new S[sisa_efektif];      
            set_union(begin(this->Engi), end(this->Engi),
                        begin(this->Skill), end(this->Skill),
                        inserter(this->inventory, begin(this->inventory)));
            for(i=0; i < this->Neff; i++){
                this->inventory[i] = T.this->inventory[i];
            }
        }
        ~Inventory(){
            delete [] this->inventory;
            delete [] this->Engi;
            delete [] this->Skill;
            this->max_capacity = 0;
            this->Neff = 0;
        }
        //Operator assignment: menyalin max_capacity, neff, dan this->inventory
        Inventory<E,S> operator=(const Inventory<E,S> T){
            int i;

            delete [] this->inventory;
            delete [] this->Engi;
            delete [] this->Skill;
            this->max_capacity = T.max_capacity;
            this->Neff = T.Neff;
            this->inventory = new string[this->max_capacity];
            this->Engi = new E[this->Neff];
            int sisa_efektif = this->max_capacity - this->Neff;            
            this->Skill = new S[sisa_efektif];      
            set_union(begin(this->Engi), end(this->Engi),
                        begin(this->Skill), end(this->Skill),
                        inserter(this->inventory, begin(this->inventory)));
            for(i=0; i < this->Neff; i++){
                this->inventory[i] = T.inventory[i];
            }

            return *this            
        }
        //Menambahkan sebuah Engimon ke dalam inventory
        Inventory<E,S>& operator<<(const E& e){
            this->Neff += 1;
            if(this->Neff < max_capacity){
                this->Engi[this->Neff-1] = e;
                set_union(begin(this->Engi), end(this->Engi),
                            begin(this->Skill), end(this->Skill),
                            inserter(this->inventory, begin(this->inventory)));
            }
            else{
                throw e;
            }
            return *this;
        }
        //Menambahkan sebuah Skill ke dalam inventory
        Inventory<E,S>& operator<<(const S& s){
            this->Neff += 1;
            if(this->Neff < max_capacity){
                this->Engi[this->Neff-1] = e;
                set_union(begin(this->Engi), end(this->Engi),
                            begin(this->Skill), end(this->Skill),
                            inserter(this->inventory, begin(this->inventory)));
            }
            else{
                throw e;
            }
            return *this;
        }
	private:
		int max_capacity; //kapasitas maksimum
		int Neff; // nilai efektif array
		//Atribut
        	string* inventory;
        	E* Engi;
		S* Skill;
		
};
