#include "malib.h"
#include <stdio.h>
#include <string.h>

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
            traiterIdentification(resteLigne);
            break;

        case '1':
            traiterTempHumaine(resteLigne);
            break;

        case '2':
            traiterTempAmbiante(resteLigne);
            break;

        case '3':
            traiterPulsation(resteLigne);
            break;

        case '4':
            traiterSignal(resteLigne);
            break;

        case '5':
            traiterEchangeDonnees(resteLigne);  
        }
    } else {
        printf("erreur ligne\n");
    }

}

void traiterIdentification(char* ligne, Beacon* beacon){
    printf("trt identification\n");
}

void traiterTempHumaine(char* ligne, Beacon* beacon){
    if()
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