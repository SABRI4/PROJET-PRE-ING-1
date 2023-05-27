#ifndef Choice11_H
#define  Choice11_H

#include <stdio.h>
#include <unistd.h>
// Importation des header du programme
#include "Stat.h"
#include "Functions.h"
#include "FightEvent.h"
#include "Choice1.h"
#include "Choice121.h"

character* choice11bis2(character* p){
    int l;
    // Fichier de la description
    const char * o = "1.1.2.txt";
    const char * x = "1.1.2.1.txt";
    const char * w = "1.1.2.2.txt";
    const char * f = "Fin.txt";
    const char * h = "after_cook.txt";
    character *b = malloc(sizeof(character)+1);
    char *n = "stat_mechant_cuisinier.txt"; // Statistiques de l'ennemie
    extraire(b, n);
    printf("\n");
    defil(o); /*  Appel de la fonction affichant les caractères des fichiers de l'histoire*/
    printf ("1.Vous creuser un trou que vous recouvrer de feuille. \n");
    printf(" 2. Vous grimper à un arbre muni de la dague en attendant qu’il passe . ");
    printf("What do you choose ? (type 1 or 2)");
    printf("\n");
    scanf("%d", &l);
    l = verif(l);
    if (l == 1){
        defil(x); /* Appel de la fonction affichant les caractères des fichiers de l'histoire*/
        defil(f); /*Fin de l'histoire*/
    }
    else if(l == 2){
        defil(w);/* Appel de la fonction affichant les caractères des fichiers de l'histoire*/
        defil(h); /* Appel de la fonction affichant les caractères des fichiers de l'histoire*/
        launch(p, b); // Combat
        defil(f); /*Fin de l'histoire*/
    }
    return p;
}

character* choice11bis(character *p){
    int l;
    // Fichier de la description
    const char * x = "1.1.1.1.txt";
    const char * w = "1.1.1.2.txt";
    const char * q = "after_oursloose.txt";
    const char * m = "after_ourswin.txt";
    const char * f = "Fin.txt";
    character *b = malloc(sizeof(character)+1);
    char *n = "stat_mechant_Ours.txt"; // Statistiques de l'ennemie
    extraire(b,n);
    printf("\n");
    printf (" 1. You melt into tears as you tell him you've lost your way and need his help to get back to civilization.  \n");
    printf(" 2.  You keep your sword in your hand, because you don't trust the talking bear. ");
    printf("What do you choose ? (type 1 or 2)");
    printf("\n");
    scanf("%d", &l);
    l = verif(l);
    if (l == 1){
        defil(x); /* Appel de la fonction affichant les caractères des fichiers de l'histoire*/
        defil(f); /*Fin de l'histoire*/
        
    }
    else if(l == 2){
        defil(w); /* Appel de la fonction affichant les caractères des fichiers de l'histoire*/
        launch(p, b); // Combat
        update_prota(p);
        save(p);
        if (p->hp <= 0){
            defil(m);
            defil(f); /*Fin de l'histoire*/
        }
        else{
            defil(q);
            defil(f); /*Fin de l'histoire*/
        } 
    }
    return p;
}

#endif
