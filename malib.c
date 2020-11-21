#include "malib.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// VECTOR


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


//  fonctions malib

void erreurligne(){}



void traiterEntree(char* ligne , Beacon* beacon){

    char zero;
    char noTrans;
    size_t timestamp;
    char resteLigne[TAILLE];
    int resultat;

    resultat = sscanf(ligne, "%zu %c%c %s", &timestamp, &zero, &noTrans, resteLigne);
    if(resultat == 4 && zero == '0' && noTrans >= '0' && noTrans <= '5' && timestamp >= beacon->timestamp){
        beacon->timestamp = timestamp;
        switch (noTrans){
        case '0':
            traiterIdentification(ligne, beacon);
            break;

        case '1':
            traiterTempHumaine(resteLigne, beacon);
            break;

        case '2':
            traiterTempAmbiante(resteLigne, beacon);
            break;

        case '3':
            traiterPulsation(resteLigne, beacon);
            break;

        case '4':
            traiterSignal(ligne, beacon);
            break;

        case '5':
            traiterEchangeDonnees(ligne, beacon);  
        }
    } else 
        erreurligne();
}

void traiterIdentification(char* ligne, Beacon* beacon){
    size_t timestamp;
    size_t id;
    unsigned char puissance;
    char vide[2];
    char num[3];
    if(sscanf(ligne, "%zu %s %zu %hhu%s", &timestamp, num, &id ,&puissance, vide) == 4){
        if(puissance < 2 || puissance > 4)
            printf("erreur puissance");
        beacon->id = id;
        beacon->puissance = puissance;
        printf("10 %zu %zu %u\n", timestamp, id, puissance);
    } else 
        erreurligne();
}

void traiterTempHumaine(char* ligne, Beacon* beacon){
    if(strncmp(ligne , "ERREUR" , TAILLE) == 0)
        traiterErreur(beacon, 0);
    else {
        float mesure;
        char vide[2];
        if(sscanf(ligne, "%f%s", &mesure, vide) == 1){
            int temperature = (int)(mesure * 10);
            if(validerTH_1(temperature)){
                beacon->valeurs[0] += mesure;
                beacon->comptValeurs[0] ++ ;
            }
            else
                beacon->comptInvalide[0]++;
        }
    }
}

void traiterTempAmbiante(char* ligne, Beacon* beacon){
    if(strncmp(ligne , "ERREUR" , TAILLE) == 0)
        traiterErreur(beacon, 1);  
    else {
        float mesure;
        char vide[2];
        if(sscanf(ligne, "%f%s", &mesure, vide) == 1){
            unsigned int version = getBuildVersion();
            if(version <= VERSION){
                short temperature = (short)(mesure * 10);
                if(validerTA_3(temperature)){
                    beacon->valeurs[1] += mesure;
                    beacon->comptValeurs[1] ++ ;
                }
                else
                    beacon->comptInvalide[1]++;
            }else {
                int temperature = (int)(mesure * 10);
                if(validerTA_1(temperature)){
                    beacon->valeurs[1] += mesure;
                    beacon->comptValeurs[1] ++ ;
                }
                else
                    beacon->comptInvalide[1]++;
            }
        }
    }
}

void traiterPulsation(char* ligne, Beacon* beacon){
    if(strncmp(ligne , "ERREUR" , TAILLE) == 0)
        traiterErreur(beacon, 2); 
    else {
        float mesure;
        char vide[2];
        if(sscanf(ligne, "%f%s", &mesure, vide) == 1){
            unsigned int version = getBuildVersion();
            if(version <= VERSION){
                short pulsation = (short)mesure;
                if(validerPulsation_3(pulsation)){
                    beacon->valeurs[2] += mesure;
                    beacon->comptValeurs[2] ++ ;
                }
                else
                    beacon->comptInvalide[2]++;
            }else {
                int pulsation = (int)mesure;
                if(validerPulsation_1(pulsation)){
                    beacon->valeurs[2] += mesure;
                    beacon->comptValeurs[2] ++ ;
                }
                else
                    beacon->comptInvalide[2]++;
            }
        }
    }
}

void traiterErreur(Beacon* beacon , int index){
    if(beacon->comptErreur[index] == 2){
            beacon->comptErreur[index] = 0 ;
            beacon->cumulErreur[index]++ ;
        } else
            beacon->comptErreur[index]++ ;
}

void traiterSignal(char* ligne, Beacon* beacon){
    size_t timestamp;
    size_t id;
    short signal;
    char vide[2];
    char num[3];
    if(sscanf(ligne, "%zu %s %hd %zu%s", &timestamp, num, &signal, &id , vide) == 4){
        unsigned int version = getBuildVersion();
            if(version <= VERSION){
                if(signal >= -128 && signal <= 127 && validerSignal_2((char)signal)){
                    appendV(&beacon->premierNiveau, id);
                    float distance = powf (10.0 ,(CONST_M - signal)/(10.0 * beacon->puissance));
                    printf("14 %zu %zu %.1f\n", timestamp, id, distance);
                }
            }else {
                if(validerSignal_3(signal)){
                    appendV(&beacon->premierNiveau, id);
                    float distance = powf (10.0 ,(CONST_M - signal)/(10.0 * beacon->puissance));
                    printf("14 %zu %zu %.1f\n", timestamp, id, distance);
                }
            }

    } else 
        erreurligne();
}

void traiterEchangeDonnees(char* ligne, Beacon* beacon){
    size_t timestamp;
    size_t id;
    char vide[100];
    char num[3];
    if(sscanf(ligne, "%zu %s %zu %s", &timestamp, num, &id , vide) >= 3){ 
        if(!containV(&beacon->premierNiveau, id))
            appendV(&beacon->premierNiveau, id);
        printf("15 %zu %zu", timestamp, beacon->id);
        for (int i = 0; i < beacon->premierNiveau.size ; i++)
            printf(" %zu", beacon->premierNiveau.data[i]);
        printf("\n");
    } else 
        erreurligne();
}

void afficherMoyennes(Beacon* beacon){
  
    for (int i = 0; i < 3; i++){
        if(beacon->comptValeurs[i] > 0)
            beacon->valeurs[i] /= beacon->comptValeurs[i];
    }
    printf("21 %.1f %.1f %zu\n", beacon->valeurs[0], beacon->valeurs[1], (size_t)beacon->valeurs[2]);
}

void afficherErreursInvalides(Beacon* beacon){

    printf("22 %zu %zu %zu\n", beacon->comptInvalide[0], beacon->comptInvalide[1], beacon->comptInvalide[2]);
}

void afficherErreursCumulees(Beacon* beacon){

    printf("23 %zu %zu %zu\n", beacon->cumulErreur[0], beacon->cumulErreur[1], beacon->cumulErreur[2]);
}

void finProgramme(Beacon* beacon){
    afficherMoyennes(beacon);
    afficherErreursInvalides (beacon);
    afficherErreursCumulees (beacon);
    
}

void afficherVersion(void){
    version_t* version = (version_t*)malloc(sizeof(version_t));
    getVersion(version);
    printf("version #: %hhu.%hhu.%u\n", version->major, version->minor, version->build);
    free(version);
}

unsigned int getBuildVersion(void){
    version_t* version = (version_t*)malloc(sizeof(version_t));
    getVersion(version);
    return version->build;
}