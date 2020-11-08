#include "malib.h"
#include "tcv.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

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
                appendV(&beacon->tempHumaines, (size_t)(mesure*10));
            else
                beacon->comptInvalide[0]++;
        } else
            erreurligne();
    }
}

void traiterTempAmbiante(char* ligne, Beacon* beacon){
    if(strncmp(ligne , "ERREUR" , TAILLE) == 0){
        if(beacon->comptErreur[1] == 2){
            beacon->comptErreur[1] = 0 ;
            beacon->cumulErreur[1]++ ;
        } else
            beacon->comptErreur[1]++ ;
        
    } else {
        float mesure;
        char vide[2];
        if(sscanf(ligne, "%f%s", &mesure, vide) == 1){
            short temperature = (short)(mesure * 10);
            if(validerTA_3(temperature))
                appendV(&beacon->tempAmbiantes, (size_t)(mesure*10 + 1000));
            else
                beacon->comptInvalide[1]++;
        } else
            erreurligne();
    }
}

void traiterPulsation(char* ligne, Beacon* beacon){
    if(strncmp(ligne , "ERREUR" , TAILLE) == 0){
        if(beacon->comptErreur[2] == 2){
            beacon->comptErreur[2] = 0 ;
            beacon->cumulErreur[2]++ ;
        } else
            beacon->comptErreur[2]++ ;
        
    } else {
        float mesure;
        char vide[2];
        if(sscanf(ligne, "%f%s", &mesure, vide) == 1){
            short pulsation = (short)mesure;
            if(validerPulsation_3(pulsation))
                appendV(&beacon->pulsations, (size_t)mesure);
            else
                beacon->comptInvalide[2]++;
        } else
            erreurligne();
    }
}

void traiterSignal(char* ligne, Beacon* beacon){
    size_t timestamp;
    size_t id;
    short signal;
    char vide[2];
    char num[3];
    if(sscanf(ligne, "%zu %s %hd %zu%s", &timestamp, num, &signal, &id , vide) == 4){
        if(validerSignal_2((char)signal)){
            appendV(&beacon->premierNiveau, id);
            float distance = powf (10.0 ,(CONST_M - signal)/(10.0 * beacon->puissance));
            printf("14 %zu %zu %.1f\n", timestamp, id, distance);
        } else 
            printf("erreur signal");  
    } else 
        erreurligne();
}

void traiterEchangeDonnees(char* ligne, Beacon* beacon){
    size_t timestamp;
    size_t id;
    char vide[100];
    char num[3];
    if(sscanf(ligne, "%zu %s %zu %s", &timestamp, num, &id , vide) >= 3){ //strtok
        if(!containV(&beacon->premierNiveau, id))
            appendV(&beacon->premierNiveau, id);
        printf("15 %zu %zu", timestamp, beacon->id);
        for (int i = 0; i < beacon->premierNiveau.size ; i++)
            printf(" %zu", beacon->premierNiveau.data[i]);
        printf("\n");
    } else 
        erreurligne();
}

void finProgramme(Beacon* beacon){
    printf("---------\nresumé\n\n");
    printf("err TH : %zu\n", beacon->cumulErreur[0]);
    printf("invalid TH : %zu\n", beacon->comptInvalide[0]);
    // for (int i = 0; i < beacon->tempHumaines.size; i++)
    //     printf("Th %d : %f , ", i,getV(&beacon->tempHumaines, i) );
    
}

