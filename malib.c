#include "malib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void erreurligne() {}

void traiterEntree(char *ligne, Beacon *beacon)
{
    char zero;
    char noTrans;
    size_t timestamp;
    char resteLigne[TAILLE];
    int resultat;
    resultat = sscanf(ligne, "%zu %c%c %s", &timestamp, &zero, &noTrans, resteLigne);
    if (resultat == 4 && zero == '0' && noTrans >= '0' && noTrans <= '5' && timestamp >= beacon->timestamp){
        beacon->timestamp = timestamp;
        switch (noTrans){
        case '0':
            traiterIdentification(ligne, beacon);
            break;
        case '1':
            traiter_int_mesure(resteLigne, beacon, validerTH_1, 0, 10);
            break;
        case '2':
            if (getBuildVersion() <= VERSION)
                traiter_short_mesure(resteLigne, beacon, validerTA_3, 1, 10);
            else
                traiter_int_mesure(resteLigne, beacon, validerTA_1, 1, 10);
            break;
        case '3':
            if (getBuildVersion() <= VERSION)
                traiter_short_mesure(resteLigne, beacon, validerPulsation_3, 2, 1);
            else
                traiter_int_mesure(resteLigne, beacon, validerPulsation_1, 2, 1);
            break;
        case '4':
            traiterSignal(ligne, beacon);
            break;
        case '5':
            traiterEchangeDonnees(ligne, beacon);
        }
    }
    else
        erreurligne();
}

void traiterIdentification(char *ligne, Beacon *beacon){
    size_t timestamp, id;
    unsigned char puissance;
    char vide[2], num[3];
    if (sscanf(ligne, "%zu %s %zu %hhu%s", &timestamp, num, &id, &puissance, vide) == 4){
        if (puissance < 2 || puissance > 4)
            printf("erreur puissance");
        beacon->id = id;
        beacon->puissance = puissance;
        printf("10 %zu %zu %u\n", timestamp, id, puissance);
    } else
        erreurligne();
}

void traiter_int_mesure(char *ligne, Beacon *beacon, bool (*f)(int), int i, int mult){
    if (strncmp(ligne, "ERREUR", TAILLE) == 0)
        traiterErreur(beacon, 1);
    else {
        float mesure;
        char vide[2];
        if (sscanf(ligne, "%f%s", &mesure, vide) == 1){
            int temperature = (int)(mesure * mult);
            if (f(temperature)){
                beacon->valeurs[i] += mesure;
                beacon->comptValeurs[i]++;
            }else
                beacon->comptInvalide[i]++;
        }
    }
}

void traiter_short_mesure(char *ligne, Beacon *beacon, bool (*f)(short), int i, int mult){
    if (strncmp(ligne, "ERREUR", TAILLE) == 0)
        traiterErreur(beacon, 1);
    else{
        float mesure;
        char vide[2];
        if (sscanf(ligne, "%f%s", &mesure, vide) == 1){
            short temperature = (short)(mesure * mult);
            if (f(temperature)){
                beacon->valeurs[i] += mesure;
                beacon->comptValeurs[i]++;
            }else
                beacon->comptInvalide[i]++;
        }
    }
}

void traiterErreur(Beacon *beacon, int index){
    if (beacon->comptErreur[index] == 2){
        beacon->comptErreur[index] = 0;
        beacon->cumulErreur[index]++;
    }else
        beacon->comptErreur[index]++;
}

void traiterSignal(char *ligne, Beacon *beacon){
    size_t timestamp, id;
    short signal;
    char vide[2], num[3];
    if (sscanf(ligne, "%zu %s %hd %zu%s", &timestamp, num, &signal, &id, vide) == 4){
        bool valide;
        if (getBuildVersion() <= VERSION)
            valide = (signal >= -128 && signal <= 127 && validerSignal_2((char)signal));
        else
            valide = validerSignal_3(signal);
        if(valide){
            appendV(&beacon->premierNiveau, id);
            printf("14 %zu %zu %.1f\n", timestamp, id, distance(signal, beacon->puissance));
        }
    }else
        erreurligne();
}

void traiterEchangeDonnees(char *ligne, Beacon *beacon){
    size_t timestamp, id;
    char vide[100], num[3];
    if (sscanf(ligne, "%zu %s %zu %s", &timestamp, num, &id, vide) >= 3){
        if (!containV(&beacon->premierNiveau, id))
            appendV(&beacon->premierNiveau, id);
        printf("15 %zu %zu", timestamp, beacon->id);
        for (int i = 0; i < beacon->premierNiveau.size; i++)
            printf(" %zu", beacon->premierNiveau.data[i]);
        printf("\n");
    }else
        erreurligne();
}

void finProgramme(Beacon *beacon){
    for (int i = 0; i < 3; i++){
        if (beacon->comptValeurs[i] > 0)
            beacon->valeurs[i] /= beacon->comptValeurs[i];
    }
    printf("21 %.1f %.1f %zu\n", beacon->valeurs[0], beacon->valeurs[1], (size_t)beacon->valeurs[2]);
    printf("22 %zu %zu %zu\n", beacon->comptInvalide[0], beacon->comptInvalide[1], beacon->comptInvalide[2]);
    printf("23 %zu %zu %zu\n", beacon->cumulErreur[0], beacon->cumulErreur[1], beacon->cumulErreur[2]);
}

void afficherVersion(void){
    version_t version ;
    getVersion(&version);
    printf("version #: %hhu.%hhu.%u\n", version.major, version.minor, version.build);
}

unsigned int getBuildVersion(void){
    version_t version ;
    getVersion(&version);
    return version.build;
}