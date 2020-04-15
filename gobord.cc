// file gobord.cc
#include <iostream>
#include "gobord.h"
using namespace std;

gobord::gobord ( ) {
  hoogte = 10;
  breedte = 10;
  maakbord();
}//gobord::gobord

gobord::~gobord ( ) {
  // TODO
}//gobord::~gobord

//Drukt van een gebouwd bord in een gobord alle
//kleuren af, van links naar rechts per rij, van de 
//bovenste rij naar de onderste
void gobord::drukaf ( ) {
  bordvakje* rij = ingang;
  bordvakje* volgende;
  for(int i = 0; i < hoogte; i++) {
    volgende = rij->buren[4]; 
    while(rij != NULL) {
      cout << rij->kleur;
      //drukafburen(rij); //debug
      rij = rij -> buren[2];
    }
    cout << endl;
    rij = volgende;
  }
}//gobord::drukaf

//Debug functie: drukt van een vakje de kleuren van
//zijn buren af. Als deze buur NULL is, drukt het n af
void gobord::drukafburen(bordvakje* vakje) {
  for(int i = 0; i < 8; i++) { //vakjes hebben 8 buren
    if(vakje->buren[i] == NULL) {
      cout << i << ": n ";
    } else {
      cout << i << ": " << vakje->buren[i]->kleur << " ";
    }
  }
    cout << endl;
}

//default contructor voor bordvakje
//kleur is leeg en alle buren op NULL
bordvakje::bordvakje ( ) {
  kleur = '.';
  for(int i = 0; i < 8; i++) {
    buren[i] = NULL;
  }
}

//Maakt een nieuwe rij van nieuwe bordvakjes, en returnt
//een pointer naar het eerste vakje van deze rij
//rij wordt zo breed als in gobord::breedte
bordvakje* gobord::maakrij() {
  bordvakje* begin = new bordvakje;
  bordvakje* eerste = begin;
  bordvakje* tweede = NULL;

  for(int i = 1; i < breedte; i++) {
    tweede = new bordvakje;
    eerste->buren[2] = tweede; //heen
    tweede->buren[6] = eerste; //en weer
    eerste=tweede;
  }
  return begin;
}

//Bij twee pointers naar (het begin van) een bovenste rij 
//en een onderste rij, ritst deze functie die aan elkaar
//door van ieder vakje van onder de buren te zetten op 
//de (links- en rechts-) bovenste en idem op de ondersten
//voor boven
void gobord::ritsen(bordvakje* boven, bordvakje* onder) {
  while(onder != NULL) {
    //noord en zuid
    onder->buren[0] = boven;
    boven->buren[4] = onder;
    //rechtsboven en terug
    onder->buren[1] = boven->buren[2];
    if(boven->buren[2] != NULL)
      boven->buren[2]->buren[5] = onder;
    //linksboven en terug
    onder->buren[7] = boven->buren[6];
    if(boven->buren[6] != NULL)
       boven->buren[6]->buren[3] = onder;
    //rechtsop schuiven
    onder = onder->buren[2];
    boven = boven->buren[2];
  }
}

//Zet gobord::ingang op de eerste nieuwe rij van
//gobord::breedte en maakt en ritst gobord::hoogte 
//nieuwe rijen van breedte gobord::breedte eronder
void gobord::maakbord() {
  ingang = maakrij();
  bordvakje* boven = ingang;
  bordvakje* onder = NULL;
  for(int i = 1; i < hoogte; i++) {
    onder = maakrij();
    ritsen(boven, onder);
    //neerschuiven
    boven = onder;
  }
}


// TODO