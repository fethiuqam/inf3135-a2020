#include "malib.h"
#include "tcv.h"
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
            traiterTempHumaine(resteLigne, beacon);
            break;

        case '2':
            traiterTempAmbiante(resteLigne, beacon);
            break;

        case '3':
            traiterPulsation(resteLigne, beacon);
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
    if(strncmp(ligne , "ERREUR" , TAILLE) == 0){
        if(beacon->comptErreur[0] == 2){
            beacon->comptErreur[0] = 0 ;
            beacon->cumulErreur[0]++ ;
        } else
            beacon->comptErreur[0]++ ;
        
    } else {
        float mesure;
        char vide[2];
        if(sscanf(ligne, "%f%s", &mesure, vide) == 1){
            int temperature = (int)(mesure * 10);
            if(validerTH_1(temperature))
                appendV(&beacon->tempHumaines, mesure);
            else
                beacon->comptInvalide[0]++;
        } else
            erreurligne();
    }
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
    printf("---------\nresumé\n\n");
    printf("err TH : %zu\n", beacon->cumulErreur[0]);
    printf("invalid TH : %zu\n", beacon->comptInvalide[0]);
    for (int i = 0; i < beacon->tempHumaines.size; i++)
        printf("Th %d : %f , ", i,getV(&beacon->tempHumaines, i) );
    
}

