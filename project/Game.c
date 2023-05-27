#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include "Stat.h"
#include "FightEvent.h"
#include "Choice1.h"
#include "Choice2.h"
#include "Choice11.h"
#include "Choice121.h"
#include "Choice212.h"
#include "Programmefile.h"

int main(){
    printf("\033[1;34m");       //On modifie la couleur et on passe le texte en gras dans le terminal
    game();                     //On lance le jNeu
    printf("\033[0m");          //On réinitialise les couleurs du terminal
    return 0;
}