#ifndef Functions_H
#define  Functions_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "Stat.h"
#define DELAY 40000


int verif(int p){
    // Permet de vérifier si l'utilisateur n'a pas fait d'erreurs d'input
    int t = 0;
    while (p != 2 && p != 1 && p != 3) {
        if (t == 0) {
            printf("An error occured, try-again: ");
            scanf("%d", &p);
            t += 1;
        } else {
            printf("Try again: ");
            scanf("%d", &p);
        }
    }
    return p;
}

int defil(const char* filen) {
    /* defile le texte lettre par lettre */
    int i = 0;
    char buffer[3000]; // Tampon de lecture
    FILE* file = fopen(filen, "r");
    if (file == NULL) {
        printf("Error occurred while opening the file.\n");
        return 1;
    }
    
    setbuf(stdout, NULL); /* désactive la mise en mémoire tampon  */

    struct timespec delay;
    delay.tv_sec = 0;               // Delai en secondes
    delay.tv_nsec = DELAY * 1000;  // Delai en nanosecondes

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        i = 0;
        while (buffer[i] != '\0') {
            printf("%c", buffer[i]);
            fflush(stdout);
            nanosleep(&delay, NULL); /* Attend un certain nombre de nanosecondes */
            i += 1;
        }
    }

    fclose(file);
    return 0;
}

void ini_prota(character* p) {
    char t;
    char* weapon1 = "Spear";        //On initialise les 3 armes 
    char* weapon2 = "Sword";
    char* weapon3 = "Bow";
    char c[100];
    remove("perso.txt");        //On supprime si le fichier existe déjà
    FILE* pl;
    pl = fopen("perso.txt", "w");       //On crée le fichier
    if (pl == NULL) {
        printf("Error occurred while opening the file.\n");     //On vérifie en cas d'erreur
        exit(1);
    }
    printf("What is your name ?\n");        //On initialise le nom du joueur
    scanf("%s", c);
    strcpy(p->name, c);   //On copie le nom dans la structure
    p->power = 46;          //On initialise la puissance par défaut
    p->hp = 100;  //On initialise la vie par défaut
    printf("You have the choice between  1. %s, 2. %s, 3. %s\n", weapon1, weapon2, weapon3);
    printf("Which weapon do you chose ? (Enter the number preceding the weapons for your selection.)\n");       //Le joueur choisi son arme parmi les 3
    scanf(" %c", &t);
    if (t == '2') {
        printf("You have chosen the sword");            
         p->eq1 = (char*)malloc(strlen(weapon2) + 1);       //On copie l'arme dans la structure
        strcpy(p->eq1, weapon2);
        p->power *= 1.45;                                   //La puissance par défaut est modifiée
    }
    else if (t == '3') {
        printf("You have chosen the bow");
        p->eq1 = (char*)malloc(strlen(weapon1) + 1);        //On copie l'arme dans la structure
        strcpy(p->eq1, weapon1);
        p->power *= 1.01;                                   //La puissance par défaut est modifiée
    }
    else if (t == '1') {
        printf("You have chosen the spear");
        p->eq1 = (char*)malloc(strlen(weapon3) + 1);        //On copie l'arme dans la structure
        strcpy(p->eq1, weapon3);
        p->power *= 1.10;                                   //La puissance par défaut est modifiée
    }
    fprintf(pl, "%d\n %s\n %s\n %f\n %d\n",p->hp, c, p->eq1, p->power , 0);     //On copie les infos du joueur dans le fichier
    fclose(pl);     //On ferme le fichier
}


void save(character* p){
    FILE *sv;
    remove(p->name);           //On supprime la sauvegarde si elle existe déjà
    sv = fopen(p->name, "w");       //Création du fichier de sauvegarde
    fprintf(sv,"%d\n %s\n %s\n %f\n %d\n",p->hp,p->name,p->eq1,p->power,p->stage); //On copie les infos du joueur dans sa sauvegarde
    //On ferme le fichier
    fclose(sv);
}



void update_prota(character *p){
    FILE *pl;
    pl = fopen("perso.txt", "w");     //on ouvre et vérifie la correcte ouverture du fichier joueur
      if (pl == NULL) {
        printf("Error occurred while opening the file.\n");
        exit(1);
        }
    fprintf(pl,"%d\n %s\n %s\n %f\n %d\n",p->hp,p->name,p->eq1,p->power,p->stage);       //On copie la structure du joueur dans son fichier  
    fclose(pl);     //On ferme le fichier joueur
}

void extraire(character *p, const char *n) {
    FILE *pl;
    pl = fopen(n, "r");
    if (pl == NULL) {
        printf("Failed to open your backup.\n");        //On ouvre le fichier à extraire et on vérifie sa correcte ouverture
        return; 
    }

    int h;
    char *nm;
    nm = malloc(sizeof(char) * 25);
    char e1[25];                    //On créé les variables que l'on va récupérer
    float po;
    int a; 

    char l1[100];
    char l2[100];
    char l3[100];
    char l4[100];           //On créé les variables pour extraire les lignes
    char l5[100];

    fgets(l1, sizeof(l1), pl);
    fgets(l2, sizeof(l2), pl);
    fgets(l3, sizeof(l3), pl);      //On récupère les lignes
    fgets(l4, sizeof(l4), pl);
    fgets(l5, sizeof(l5), pl);

    sscanf(l1, "%d", &h);
    sscanf(l2, "%s", nm);
    sscanf(l3, "%s", e1);           //On transforme les lignes dans les variables avec le type qui convient
    sscanf(l4, "%f", &po);
    sscanf(l5, "%d", &a);

    p->hp = h;
    int i = 0;
    while(*(nm+i)!='\0'){
        p->name[i] = *(nm+i);    
        i++;
    } 
    p->eq1 = strdup(e1);            //Les informations sont copiés dans la structure 
    p->power = po;
    p->stage = a;

    fclose(pl);
}

character* begin(int *b){
    printf("Would you like to load a backup? Please enter Y or N.");
    char c;
    character *p = malloc(sizeof(character));;            //On demande si le joueur charge une sauvegarde ou entame une nouvelle partie
    scanf("%c",&c);
    if(c == 'Y'){
        printf("Enter your username.");             //A partir du nom du joueur on va récupérer ses infos dans la structure
        char n[25];
        scanf("%s",n);
        *b = 1;                      //Ce pointeur nous est utile dans la fonction game
        extraire(p,n);
    }
    if(c == 'N'){
        *b = 0;                     //Ce pointeur nous est utile dans la fonction game
        ini_prota(p);       //On initialise le joueur
    }
    return p;
}


#endif