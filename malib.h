#ifndef MALIB_H
#define MALIB_H

#include "vector.h"
#include "tcv.h"
#include <stdio.h>

#define TAILLE 100
#define DEFAUT_ID 9999
#define DEFAUT_PUISSANCE 2
#define CAPACITY 2
#define CONST_M -69

typedef struct beacon_s {
    size_t timestamp;
    size_t id;
    unsigned char puissance;
    Vector tempHumaines;
    Vector tempAmbiantes;
    Vector pulsations;
    Vector premierNiveau;
    size_t comptInvalide[3];
    unsigned char comptErreur[3];
    size_t cumulErreur[3];
} Beacon;


void traiterEntree(char* ligne , Beacon* beacon);

void traiterIdentification(char* ligne, Beacon* beacon);

void traiterTempHumaine(char* ligne, Beacon* beacon);

void traiterTempAmbiante(char* ligne, Beacon* beacon);

void traiterPulsation(char* ligne, Beacon* beacon);

void traiterErreur(Beacon* beacon , int index);

void traiterSignal(char* ligne, Beacon* beacon );

void traiterEchangeDonnees(char* ligne, Beacon* beacon);

void finProgramme(Beacon* beacon);

void afficherVersion();


#endif