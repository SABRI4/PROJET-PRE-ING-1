#ifndef Choice1_H
#define  Choice1_H

#include "Functions.h"
#include <stdio.h>
#include <unistd.h>
// Importation des header du programme
#include "FightEvent.h"
#include "Stat.h"
#include "Functions.h"
#include "Choice2.h"
#include "Choice11.h"
#include "Choice121.h"
#include "Choice212.h"

character* choice12s(character*p){
    int l;
    // Fichier de la description
    const char * s = "1.2.txt";
    defil(s); /*  Appel de la fonction affichant les caractères des fichiers de l'histoire*/
    printf ("1. Cross the river by jumping from stone to stone\n");
    printf(" 2. You follow the course of the water to find a safer passage. ");
    scanf("%d", &l);
    l = verif(l);
    if (l == 1){
        p->stage = 7;
        choicegt(p);
        
    }
    else if(l == 2){
        p->stage = 8;
        choicegt2(p);
    }
    return p;
}

character* choice11s(character *p){
    int n;
    // Fichier de la description
    const char * l = "1.1.txt"; 
    const char * i = "1.1.1.txt";
    const char * u = "1.1.2.txt";
    defil(l); /*  Appel de la fonction affichant les caractères des fichiers de l'histoire*/
    printf ("1. Approach with caution, armed with your sword, ready to face any situation.\n");
    printf(" 2. Throw your sword at the figure with all your might and see what happens. ");
    printf("What do you choose ?");
    scanf("%d", &n);
    n = verif(n);
    if (n == 1){
        defil(i); /*  Appel de la fonction affichant les caractères des fichiers de l'histoire*/
        p->stage = 5;
        choice11bis(p);
        
    }
    else if(n == 2){
        defil(u); /* Appel de la fonction affichant les caractères des fichiers de l'histoire*/
        p->stage = 6;
        choice11bis2(p);
    }
    return p;
}

character* choice1(character * p){
    int l;
    const char * g = "1.txt"; // Fichier de la description
    defil(g); /* Appel de la fonction affichant les caractères des fichiers de l'histoire*/
    printf("1. The left road\n");
    printf("2. The right path\n");
    printf("What do you choose ?");
    scanf("%d", &l);
    verif(l);
    if (l == 1){
        p->stage = 3;
        choice11s(p);
    }
    else if(l == 2){
        p->stage = 4;
        choice12s(p);
    }
    return p;
}


#endif
