#ifndef Choice121_H
#define  Choice121_H



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h> 
// Importation des header du programme
#include "Stat.h"
#include "Functions.h"
#include "FightEvent.h"
#include "Choice2.h"
#include "Choice11.h"
#include "Choice1.h"
#include "Choice212.h"

character* choicegt2(character *p){
    int l;
    // Fichier de la description
    const char * q = "1.2.2.txt";
    const char * v = "1.2.2.1.txt";
    const char * k = "1.2.2.2.txt";
    const char * f = "Fin.txt";
    defil(q);
    printf ("1. Jump into the water, aligning your body so as not to hurt yourself. . \n");
    printf(" 2. Go back the way you came and find the little stone bridge .  ");
    printf("What do you choose ?");
    scanf("%d", &l);
    l = verif(l);
    if (l == 1){
        defil(v); /*  Appel de la fonction affichant les caractères des fichiers de l'histoire*/
        defil(f); /* Fin de l'histoire*/
        
    }
    else if(l == 2){
        defil(k); /*  Appel de la fonction affichant les caractères des fichiers de l'histoire*/
        defil(f); /*Fin de l'histoire*/
    }
    return p;
}

character* choicegt(character * p){
    int l;
    // Fichier de la description
    const char * s = "1.2.1.txt";
    const char * k = "1.2.1.1.txt";
    const char * j = "1.2.1.2.txt";
    const char * f = "Fin.txt";
    character *b = malloc(sizeof(character)+1); 
    char *n = "stat_mechant_carpe.txt"; // Statistiques de l'ennemie
    extraire(b, n);
    defil(s);
    printf ("1. Escape by jumping over the other stones as quickly as possible.  \n");
    printf(" 2. Fight carp with your bare hands. ");
    scanf("%d", &l);
    l = verif(l);
    if (l == 1){
        defil(k); /*  Appel de la fonction affichant les caractères des fichiers de l'histoire*/
        defil(f); /*Fin de l'histoire*/
        
    }
    else if(l == 2){
        defil(j); /*  Appel de la fonction affichant les caractères des fichiers de l'histoire*/
        launch(p, b);
        update_prota(p);
        if (p->hp <=0){
            printf("You loose");
            defil(f);
        }
        else{
            printf("You won");
            defil(f);
        } /*Fin de l'histoire*/
    }
    return p;
}
#endif
