#ifndef Choice212_H
#define  Choice212_H

#include <stdio.h>
#include <unistd.h>
// Importation des header du programme
#include "FightEvent.h"
#include "Stat.h"
#include "Functions.h"
#include "Choice2.h"
#include "Choice11.h"
#include "Choice121.h"
#include "Choice1.h"

character* choice21bis2(character* p){
    int l;
    // Fichier de la description
    const char * g = "2.1.2.1.txt";
    const char * o = "2.1.2.2.txt";
    const char * f = "Fin.txt";
    printf ("1. Approach the rock and examine the symbols\n");
    printf(" 2. Continue on your way without stopping.  ");
    printf("What do you choose ?");
    scanf("%d", &l);
    l = verif(l);
    if (l == 1){
        defil(g); /*  Appel de la fonction affichant les caractères des fichiers de l'histoire*/
        defil(f); /*Fin de l'histoire*/
    }
    else if(l == 2){
         defil(o); /*  Appel de la fonction affichant les caractères des fichiers de l'histoire*/
         defil(f); /*Fin de l'histoire*/
    }
    return p;
}

#endif
