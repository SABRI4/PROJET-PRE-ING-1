#ifndef Choice212_H
#define  Choice212_H

#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
// Importation des header du programme
#include "Stat.h"
#include "Functions.h"

character* choice21bis2(character* p){
    int l;
    // Fichier de la description
    const char * g = "2.1.2.1.txt";
    const char * o = "2.1.2.2.txt";
    const char * f = "Fin.txt";
    printf("\n");
    printf ("1. Approach the rock and examine the symbols\n");
    printf(" 2. Continue on your way without stopping.  ");
    printf("\n");
    printf("What do you choose ? (type 1 or 2)");
    printf("\n");
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
