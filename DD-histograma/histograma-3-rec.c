#include <stdio.h>
#include "graficador.h"
#include <ctype.h>

void stateOut(unsigned cc, unsigned vectorContador[], int cantContadores, FILE* );
void stateIn(unsigned cc, unsigned vectorContador[], int cantContadores, FILE* );


void cantidadDePalabrasPorSuLongitud (unsigned vectorContador[], int cantContadores ,FILE* file ){
    unsigned cc = 0;
    int flujo;

    do  {
        flujo = getc(file);

            if(isspace(flujo) != 0){
               stateOut(cc,vectorContador, cantContadores, file);
            }   else {
                if (flujo != EOF){
                    stateIn(cc, vectorContador, cantContadores, file);
                }
               }

    }  while (flujo != EOF);
}
  

void stateOut(unsigned cc, unsigned vectorContador[], int cantContadores, FILE* file){
    
        if (cc != 0){
            if(cc > cantContadores - 1){cc=cantContadores;}
                vectorContador[cc-1]++;
                cc=0;
            return;
        }
}

void stateIn(unsigned cc, unsigned vectorContador[], int cantContadores, FILE* file){
    cc++;
    int flujo = getc(file);

    if ((isspace(flujo) == 0) && flujo != EOF){
        stateIn(cc, vectorContador, cantContadores, file);
    } else {
        stateOut(cc,vectorContador, cantContadores, file);
    }
}


