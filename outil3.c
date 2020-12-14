#include "outil3.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void initV(Vector *vector, int capacity) {
  vector->size = 0;
  vector->capacity = capacity;
  vector->data = (size_t*)malloc(sizeof(size_t) * vector->capacity);
  for (int i=vector->size;i < vector->capacity; ++i) {
    setV(vector, i, 0);
  }
}

void appendV(Vector *vector, size_t value) {
  extendV(vector);
  vector->data[vector->size++] = value;
}

size_t getV(Vector *vector, int index) {
  if (index >= vector->size || index < 0) {
    printf("Index %d out of bounds for vector of size %d\n", index, vector->size);
    exit(1); 
  }
  return vector->data[index];
}

void setV(Vector *vector, int index, size_t value) {
  if (index < vector->size && index >= 0) {
    vector->data[index] = value;
  }
}

void extendV(Vector *vector) {
  if (vector->size >= vector->capacity) {
    vector->capacity *= 2;
    vector->data = (size_t*)realloc(vector->data, sizeof(size_t) * vector->capacity);
  }
}

void freeV(Vector *vector) {
  free(vector->data);
}

bool containV(Vector *vector, size_t value){
  for (int i = 0; i < vector->size; i++){
    if (vector->data[i] == value)
      return true;
  }
  return false;
}

float distance(int _signal, int _power){
    return powf (10.0 ,(CONST_M - _signal)/(10.0 * _power));
}

int cmd(int argc, char* argv[], Beacon* beacon){
    return 0;
}