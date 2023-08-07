#include <stdio.h>
#include "graficador.h"

#define IMPLEMENTACION_3

void stateOut(unsigned cc, unsigned vectorContador[], int cantContadores, FILE* );
void stateIn(unsigned cc, unsigned vectorContador[], int cantContadores, FILE* );


void cantidadDePalabrasPorSuLongitud (unsigned vectorContador[], int cantContadores ,FILE* file ){
    unsigned cc = 0;

    int flujo;

    do  {
        flujo = getc(file);
        if(flujo == ' ' || flujo == '\n' || flujo == '\t' || flujo == EOF){
            stateOut(cc,vectorContador, cantContadores, file);
        }   else {
                stateIn(cc, vectorContador, cantContadores, file);
            }
        
    }  while (flujo != EOF);

}
  

void stateOut(unsigned cc, unsigned vectorContador[], int cantContadores, FILE* file){
    
    int flujo; 
        if (cc != 0){
            if(cc > cantContadores - 1){
                vectorContador[cantContadores-1]++;
                cc=0;
            }   else {
                    vectorContador[cc-1]++;
                    cc=0; 
                }
        return;
        }
    
}

void stateIn(unsigned cc, unsigned vectorContador[], int cantContadores, FILE* file){
    cc++;
    int flujo = getc(file);

    if (flujo != ' ' && flujo != '\n' && flujo != '\t' && flujo != EOF){
        stateIn(cc, vectorContador, cantContadores, file);
    } else {
        stateOut(cc,vectorContador, cantContadores, file);
    }
}

#undef IMPLEMENTACION_2



