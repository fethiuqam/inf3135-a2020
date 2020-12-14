#include "outil3.h"
#include "malib.h"
#include <stdio.h>

int main (int argc , char* argv[] ){
    char ligne[TAILLE];
    Beacon beacon;
    beacon.timestamp = 0;
    beacon.id = DEFAUT_ID;
    beacon.puissance = DEFAUT_PUISSANCE;
    initV(&beacon.premierNiveau, CAPACITY);
    for (int i = 0; i < 3; ++i){
        beacon.valeurs[i] = 0.0;
        beacon.comptValeurs[i] = 0;
        beacon.comptErreur[i] = 0 ;
        beacon.comptInvalide[i] = 0 ;
        beacon.cumulErreur[i] = 0 ;
        beacon.infos[i] = 0;
    }
    for (int i = 0; i < 6; ++i)
        beacon.compteurTrx[i] = 0;
    for (int i = 0; i < 4; ++i)
        beacon.options[i] = false; 

    cmd(argc, argv, &beacon);

    afficherVersion();
    while (fgets(ligne,  TAILLE , stdin) != NULL){
        traiterEntree(ligne , &beacon);
    }
    if(!beacon.options[3])
        finProgramme(&beacon);
    if(beacon.options[0])
        afficherInfoInvalide(&beacon);
    if(beacon.options[1])
        afficherInfoDetail(&beacon);

    freeV(&beacon.premierNiveau);
    return 0;
}