#ifndef MALIB_H
#define MALIB_H

#include "tcv.h"
#include "outil3.h"
#include <stdio.h>
#include <stdbool.h>

#define DEFAUT_ID 9999
#define DEFAUT_PUISSANCE 2
#define VERSION 1003

void traiterEntree(char* ligne , Beacon* beacon);
void traiter_int_mesure(char *ligne, Beacon *beacon, bool (*f)(int), int i, int mult);
void traiter_short_mesure(char *ligne, Beacon *beacon, bool (*f)(short), int i, int mult);
void traiterIdentification(char* ligne, Beacon* beacon);
void traiterErreur(Beacon* beacon , int index);
void traiterSignal(char* ligne, Beacon* beacon );
void traiterEchangeDonnees(char* ligne, Beacon* beacon);
void finProgramme(Beacon* beacon);
void afficherVersion(void);
unsigned int getBuildVersion(void);
void afficherInfoInvalide(Beacon *beacon);
void afficherInfoDetail(Beacon *beacon);
void afficherInfoSommaire(Beacon *beacon);

#endif