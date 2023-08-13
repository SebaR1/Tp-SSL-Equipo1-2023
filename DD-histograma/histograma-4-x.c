#include <stdio.h>
#include "graficador.h"
#include <ctype.h>

#define STATE_OUT 0
#define STATE_IN 1

void sumarPalabra(unsigned vector[], int cantContadores, int cc);

void cantidadDePalabrasPorSuLongitud (unsigned vectorContador[], int cantContadores ,FILE* file )
{
    unsigned cc = 0;
    int flujo = getc(file);
    int state = STATE_OUT;

    while (flujo != EOF){

        if(isspace(flujo) != 0){
            if(state == STATE_IN){
                sumarPalabra(vectorContador, cantContadores, cc);
                cc=0;
                state = STATE_OUT;
                }
        } else {
            ++cc;
            state = STATE_IN;
        } 
        flujo = getc(file);
    }
    sumarPalabra(vectorContador, cantContadores, cc);
}

void sumarPalabra(unsigned vectorContador[], int cantContadores, int cc){
        if(cc > cantContadores - 1){cc=cantContadores;}
            vectorContador[cc-1]++;
            cc=0;
}

