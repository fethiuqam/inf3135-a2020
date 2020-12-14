#ifndef _OUTIL3_H_
#define _OUTIL3_H_

#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 2
#define CONST_M -69
#define TAILLE 100

typedef struct vector_s{
  int size;      // slots used so far
  int capacity;  // total available slots
  size_t *data;     // array of integers we're storing
} Vector;

typedef struct beacon_s {
    size_t timestamp, id;
    unsigned char puissance;
    float valeurs[3];
    int comptValeurs[3],compteurTrx[6], infos[3];
    Vector premierNiveau;
    size_t comptInvalide[3];
    unsigned char comptErreur[3];
    size_t cumulErreur[3];
    bool options[4];
} Beacon;

void initV(Vector *vector, int capacity);
void appendV(Vector *vector, size_t value);
size_t getV(Vector *vector, int index);
void setV(Vector *vector, int index, size_t value);
void extendV(Vector *vector);
void freeV(Vector *vector);
bool containV(Vector *vector, size_t value);

float distance(int _signal, int _power);
void cmd(int argc, char* argv[], Beacon* beacon);
int compare(const void* a, const void* b);
void trierTableau(Vector* tableau);

#endif