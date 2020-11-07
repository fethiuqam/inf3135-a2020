#include "malib.h"
#include <stdio.h>



int main (int argc , char* argv[] ){

    char ligne[TAILLE];
    // initialisation de l'objet beacon 
    Beacon beacon;
    beacon.id = DEFAUT_ID;
    beacon.puissance = DEFAUT_PUISSANCE;
    initV(&beacon.tempHumaines, CAPACITY);
    initV(&beacon.tempAmbiantes, CAPACITY);
    initV(&beacon.pulsations, CAPACITY);
    initV(&beacon.premierNiveau, CAPACITY);
    for (int i = 0; i < 3; ++i){
        beacon.comptErreur[i] = 0 ;
        beacon.comptInvalide[i] = 0 ;
        beacon.cumulErreur[i] = 0 ;
    }
    
    while (fgets(ligne,  TAILLE , stdin) != NULL){
        traiterEntree(ligne , &beacon);
    }

    finProgramme(&beacon);

    return 0;
}