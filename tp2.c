#include "malib.h"
#include <stdio.h>

#define TAILLE_TAMPON 100

int main (int argc , char* argv[] ){

    char ligne[TAILLE_TAMPON];

    while (fgets(ligne,  TAILLE_TAMPON , stdin) != NULL){
        traiterEntree(ligne);
    }

    finProgramme();

    return 0;
}