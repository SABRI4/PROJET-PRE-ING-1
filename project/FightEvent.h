#ifndef FightEvent_H
#define FightEvent_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h> 
// Importation des header du programme
#include "Stat.h"
#include "Functions.h"

// Fonction de combat
void fight(character *p, character *b) {
    printf("Beginning of the fight bewteen %s and %s\n", p->name, b->name);

    // Boucle de combat jusqu'à ce que l'un des personnages n'ait plus de vie
    while (p->hp > 0 && b->hp > 0) {
        // Calcul des dégâts infligés par le personnage joueur et l'ennemi
        int player_damage = (p->power > b->hp) ? b->hp : p->power;
        int enemy_damage = (b->power > p->hp) ? p->hp : b->power;

        // Réduction des points de vie des personnages en fonction des dégâts
        p->hp -= enemy_damage;
        b->hp -= player_damage;
        update_prota(p);
        save(p);
    }
    if (p->hp <= 0 && b->hp <= 0) {
      printf("You died with the enemy!\n");
    } 
    else if (b->hp <= 0 && p->hp > 0) {
      printf("%s is KO, you beat the enemy!\n", b->name);
    } 
    else {
      printf("You were killed by %s. %s won the fight!\n", b->name, p->name);
    }

}


character * launch(character *p, character *b) {
  printf("\n ---------------\n FIIIIGGHHTTTT \n ---------------\n");
  fight(p, b);
  return p;
}

#endif
