#ifndef MALIB_H
#define MALIB_H


#include "tcv.h"
#include <stdio.h>
#include <stdbool.h>

#define TAILLE 100
#define DEFAUT_ID 9999
#define DEFAUT_PUISSANCE 2
#define CAPACITY 2
#define CONST_M -69
#define VERSION 1003

// VECTOR

typedef struct vector_s{
  int size;      // slots used so far
  int capacity;  // total available slots
  size_t *data;     // array of integers we're storing
} Vector;

void initV(Vector *vector, int capacity);
void appendV(Vector *vector, size_t value);
size_t getV(Vector *vector, int index);
void setV(Vector *vector, int index, size_t value);
void extendV(Vector *vector);
void freeV(Vector *vector);
bool containV(Vector *vector, size_t value);

// malib

typedef struct beacon_s {
    size_t timestamp;
    size_t id;
    unsigned char puissance;
    float valeurs[3];
    int comptValeurs[3];
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

void afficherVersion(void);

unsigned int getBuildVersion(void);

#endif