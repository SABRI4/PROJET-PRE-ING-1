#ifndef FightEvent_H
#define FightEvent_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h> 
// Importation des header du programme
#include "Stat.h"


character *round_fight(character * attacker, character * defender) {
  float damage;
  if (attacker->hp <= 0){
      return defender;
  }
    damage =  attacker->power ; // Ajuste les dégâts du héro en fonction de l'arme choisit 
    defender->hp -= damage;
    return defender;
 }

void fight(character *bad_guy, character *hero) {
  while (bad_guy->hp > 0 && hero->hp > 0) {
    hero = round_fight(hero, bad_guy);    //hero attacks with fixed weapon
    sleep(0.5);                                          // wait for one second
    bad_guy = round_fight(bad_guy, hero);            // Enemi attacks
    sleep(0.5);                                        // wait for one second
    
  }
  if (hero->hp <= 0 && bad_guy->hp <= 0) {
    printf("C'est un carnage ! Vous êtes mort en tuant le monstre !\n");
  } 
  else if (bad_guy->hp <= 0) {
    printf("%s est KO, vous avez triomphé du monstre !\n", bad_guy->name);
  } 
  else {
    printf("Hélas, vous vous êtes fait tuer par %s. %s a gagné le combat !\n", bad_guy->name, bad_guy->name);
  }
}

void launch(character *p, character *b) {
  srand(time(NULL));
  printf("\n ---------------\n FIIIIGGHHTTTT \n ---------------\n");
  fight(b, p);
}

#endif
