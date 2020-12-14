#ifndef _OUTIL3_H_
#define _OUTIL3_H_

#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 2
#define CONST_M -69

typedef struct vector_s{
  int size;      // slots used so far
  int capacity;  // total available slots
  size_t *data;     // array of integers we're storing
} Vector;

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

void initV(Vector *vector, int capacity);
void appendV(Vector *vector, size_t value);
size_t getV(Vector *vector, int index);
void setV(Vector *vector, int index, size_t value);
void extendV(Vector *vector);
void freeV(Vector *vector);
bool containV(Vector *vector, size_t value);

float distance(int _signal, int _power);
int cmd(int argc, char* argv[], Beacon* beacon);

#endif