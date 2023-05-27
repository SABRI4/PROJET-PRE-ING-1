#ifndef Choice2_H
#define  Choice2_H



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h> 
// Importation des header du programme
#include "Stat.h"
#include "Functions.h"
#include "FightEvent.h" 
#include "Choice1.h"
#include "Choice11.h"
#include "Choice121.h"
#include "Choice212.h"

character* choice21s(character *p){
    int l;
    // Fichier de la description
    const char * n = "2.1.txt";
    const char * x = "2.1.1";
    const char * w = "2.1.2";
    const char * f = "Fin.txt";
    character *b = malloc(sizeof(character)+1);
    const char *h = "stat_mechant_ronces.txt"; // Statistiques de l'ennemie
    extraire(b, h);
    defil(n); /*  Appel de la fonction affichant les caractères des fichiers de l'histoire*/
    scanf("%d", &l);
    l = verif(l);
    printf("1. You decide to explore the enchanted glade and mingle with the fairy creatures..\n");
    printf("2. You decide to end your melody and leave the clearing, thinking that perhaps it's best not to linger too long in this enchanted world.\n");
    if (l == 1){
        defil(x); /* Appel de la fonction affichant les caractères des fichiers de l'histoire*/
        launch(p, b);
        update_prota(p);
        if (p->hp <=0){
            defil(f); /*Fin de l'histoire*/
        }
        else{
            choice21bis2(p);
        } 
    }
    else if(l == 2){
        defil(w); /* Appel de la fonction affichant les caractères des fichiers de l'histoire*/
        p->stage = 10;
        choice21bis2(p); /*Appel de la fonction affichant les caractères des fichiers de l'histoire*/
    }
    return p;
}

character* choice2(character *p){
    int l;
    // Fichier de la description
    const char * n =  "2.txt";
    const char * d =  "2.2.txt";
    const char * f =  "Fin.txt";
    defil(n);
    printf("1. You sit back and blow into the flute, letting your mind lose itself in its haunting melody.\n");
    printf("2. You decide to leave the clearing and return to the path, thinking it best not to linger in this mysterious place.\n");
    printf("What do you choose ?");
    scanf("%d", &l);
    l = verif(l);
    if (l == 1){
        p->stage = 9;
        choice21s(p); /* Appel de la fonction affichant les caractères des fichiers de l'histoire*/
        
    }
    else if(l == 2){
        defil(d); /* Appel de la fonction affichant les caractères des fichiers de l'histoire*/
        defil(f); /* Fin de l'histoire*/
    }
    return p;
}



#endif
