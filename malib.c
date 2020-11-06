#include "malib.h"
#include <stdio.h>

#define TAILLE 100

void traiterEntree(char* ligne){

    char zero;
    char noTrans;
    size_t timestamp;
    char resteLigne[TAILLE];
    int resultat;

    resultat = sscanf(ligne, "%d %c%c %s", &timestamp, &zero, &noTrans, resteLigne);
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
        printf("erreur ligne");
    }

}

void traiterIdentification(char* ligne){
    printf("trt identification");
}

void traiterTempHumaine(char* ligne){
    printf("trt temperature humaine");
}

void traiterTempAmbiante(char* ligne){
    printf("trt temperature ambiante");
}

void traiterPulsation(char* ligne){
    printf("trt pulsation");
}

void traiterSignal(char* ligne){
    printf("trt signal");
}

void traiterEchangeDonnees(char* ligne){
    printf("trt echange donnees");
}

void finProgramme(){
    printf("fin du programmme");
}