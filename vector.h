// vector.c ** exemple pedagogique MIT license GF 2019 **
// Un TAD type de donnees abstrait en C
// Ne pas utiliser ceci (tel quel) en production.
#ifndef VECTOR_H
#define VECTOR_H


typedef struct {
  int size;      // slots used so far
  int capacity;  // total available slots
  float *data;     // array of integers we're storing
} Vector;

void initV(Vector *vector, int capacity);
void appendV(Vector *vector, float value);
float getV(Vector *vector, int index);
void setV(Vector *vector, int index, float value);
void extendV(Vector *vector);
void freeV(Vector *vector);



#endif

// int main() {
//   // declare and initialize a new vector
//   Vector vector;
//   initV(&vector,2);
//   printf("capacite : %d et nombre de valeur : %d\n", vector.capacity, vector.size);

//   // fill it up with 150 arbitrary values this should expand capacity
//   for (int i = 200; i > -50; i--) {
//     appendV(&vector, i);
//   }

//   setV(&vector, 921, 212984);

//   printf("valeur a l'index 27: %d\n", getV(&vector, 27));
//   setV(&vector, 27, 88);
//   printf("valeur a l'index 27: %d\n", getV(&vector, 27));

//   printf("capacite : %d et nombre de valeur : %d\n", vector.capacity, vector.size);

//   freeV(&vector);
// }