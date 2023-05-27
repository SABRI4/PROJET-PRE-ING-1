#ifndef Stat_H
#define Stat_H

typedef struct {
    int hp;     //points de vie du personnage
    char name[25];     //nom du personnage
    char* eq1;      //équipements du personnage
    float power;      //puissance du personnage
    int stage;    //code permettant de retrouver où est précisément le joueur dans l'histoire selon ces choix
} character;

#endif