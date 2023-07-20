#include <stdio.h>
#include "histograma.h"

void cantidadDePalabrasPorSuLongitud (unsigned vectorContador[], int cantContadores ,FILE* file )
{
    unsigned cc = 0;

    int flujo = getc(file);

    do {
    if(flujo == ' ' || flujo == '\n' || flujo == '\t' || flujo == EOF){
        stateOut(cc,vectorContador, cantContadores, file);
    }   else {
            stateIn(cc, vectorContador, cantContadores, file);
        }

        flujo = getc(file);

    } while (flujo != EOF);

}


void stateOut(unsigned cc, unsigned vectorContador[], int cantContadores, FILE* file) {
    if (cc != 0) {
        if (cc >= cantContadores - 1) {
            vectorContador[cantContadores - 1]++;
        } else {
            vectorContador[cc - 1]++;
        }
        cc = 0;
    }

    int flujo = getc(file);
    while (flujo == ' ' || flujo == '\n' || flujo == '\t') {
        flujo = getc(file);
    }

    if (flujo != EOF) {
        stateIn(1, vectorContador, cantContadores, file);
    }
}

void stateIn(unsigned cc, unsigned vectorContador[], int cantContadores, FILE* file) {
    int flujo = getc(file);

    if (flujo == ' ' || flujo == '\n' || flujo == '\t' || flujo == EOF) {
        stateOut(cc, vectorContador, cantContadores, file);
    } else {
        
        stateIn(cc + 1, vectorContador, cantContadores, file);
    }
}