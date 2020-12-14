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
    }
    beacon.infoInvalide = false;
    beacon.InfoDetail = false;
    beacon.infoSommaire = false;
    beacon.tranquille = false;

    cmd(argc, argv, &beacon);

    afficherVersion();
    while (fgets(ligne,  TAILLE , stdin) != NULL){
        traiterEntree(ligne , &beacon);
    }
    if(!beacon.tranquille)
        finProgramme(&beacon);
        
    freeV(&beacon.premierNiveau);
    return 0;
}