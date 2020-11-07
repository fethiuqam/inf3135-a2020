#include "malib.h"
#include <stdio.h>
#include <string.h>

void erreurligne(){
    printf("erreur ligne\n");
}

void traiterEntree(char* ligne , Beacon* beacon){

    char zero;
    char noTrans;
    size_t timestamp;
    char resteLigne[TAILLE];
    int resultat;

    resultat = sscanf(ligne, "%zu %c%c %s", &timestamp, &zero, &noTrans, resteLigne);
    if(resultat == 4 && zero == '0' && noTrans >= '0' && noTrans <= '5'){
        switch (noTrans){
        case '0':
            traiterIdentification(ligne, beacon);
            break;

        case '1':
            traiterTempHumaine(ligne, beacon);
            break;

        case '2':
            traiterTempAmbiante(ligne, beacon);
            break;

        case '3':
            traiterPulsation(ligne, beacon);
            break;

        case '4':
            traiterSignal(ligne);
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
    printf("trt temperature humaine\n");
}

void traiterTempAmbiante(char* ligne, Beacon* beacon){
    printf("trt temperature ambiante\n");
}

void traiterPulsation(char* ligne, Beacon* beacon){
    printf("trt pulsation\n");
}

void traiterSignal(char* ligne){
    printf("trt signal\n");
}

void traiterEchangeDonnees(char* ligne, Beacon* beacon){
    printf("trt echange donnees\n");
}

void finProgramme(Beacon* beacon){
    printf("fin du programmme\n");
}

