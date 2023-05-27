#ifndef Programmefile_H
#define  Programmefile_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "Functions.h"
#include "Stat.h"
#include "Choice1.h"
#include "Choice2.h"
#include "Choice11.h"
#include "Choice121.h"
#include "Choice212.h"

void intro(character *p){
    int c;
    const char * i = "intro.txt";
    printf("\n");
    defil(i);
    printf("\n");
    printf("If you want to follow the trail, type 1.\nIf you want to explore the clearing, type 2.\n");
    scanf("%d",&c);             //Le joueur choisi sa prochaine étape, l'info est récupéré dans la variable c
    verif(c);
    if(c == 1){
        p->stage = 1;             //On modifie la position du joueur dans l'histoire
        choice1(p);                 //On appelle la fonction en conséquence de son choix selon l'histoire
    }
    else if(c == 2){
        p->stage = 2;            //On modifie la position du joueur dans l'histoire
        choice2(p);             //On appelle la fonction en conséquence de son choix selon l'histoire
    }
}

void game(){
    character *p;
    p = malloc(sizeof(character));      //On déclare la structure du joueur
    int b;
    b = 0;
    p = begin(&b);               //b est le pointeur que l'on voit dans la fonction begin, il permet de différencier une nouvelle partie d'un chargement de sauvegarde
    if(!b){    
        intro(p);               //On lance l'histoire
    }
    else{
        switch(p->stage){       //Selon la position du joueur dans l'histoire représentée par le champ stage, on lance l'histoire la où le joeur s'est arrêté
    case 1 :
    choice1(p);
    break;

    case 2 :
    choice2(p);
    break;

    case 3 :
    choice11s(p);
    break;

    case 4 :
    choice12s(p);
    break;

    case 5 :
    choice11bis(p);
    break;

    case 6 :
    choice11bis2(p);
    break;

    case 7 :
    choicegt(p);
    break;

    case 8 :
    choicegt2(p);
    break;

    case 9 : 
    choice21s(p);
    break;

    case 10 : 
    choice21bis2(p);
    break;
    }
    }
}

#endif