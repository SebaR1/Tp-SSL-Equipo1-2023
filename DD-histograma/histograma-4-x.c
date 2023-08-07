#include <stdio.h>
#include "graficador.h"

void sumarValorAVector(unsigned vector[], int cantContadores, int cc);

#define IMPLEMENTACION_4
void cantidadDePalabrasPorSuLongitud (unsigned vectorContador[], int cantContadores ,FILE* file )
{
    unsigned cc = 0;
    int flujo = getc(file);

    while (flujo != EOF){

        if(flujo == ' ' || flujo == '\n' || flujo == '\t' || flujo == EOF){
            sumarValorAVector(vectorContador, cantContadores, cc);
            cc=0;
        } else {
            ++cc;
        } 
    
        flujo = getc(file);
    }
    sumarValorAVector(vectorContador, cantContadores, cc);
}

void sumarValorAVector(unsigned vectorContador[], int cantContadores, int cc){
        if(cc > cantContadores - 1){
            vectorContador[cantContadores-1]++;
            cc=0;
        }   else {
                if(cc!=0){
                    vectorContador[cc-1]++;
                    cc=0; 
                }
            }
}

#undef IMPLEMENTACION_4

