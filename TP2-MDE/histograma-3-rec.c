#include <stdio.h>
#include "histograma.h"
void stateOut(unsigned cc, unsigned vectorContador[], int cantContadores, FILE* );
void stateIn(unsigned cc, unsigned vectorContador[], int cantContadores, FILE* );

void cantidadDePalabrasPorSuLongitud (unsigned vectorContador[], int cantContadores ,FILE* file )
{
    unsigned cc = 0;

    int flujo = getc(file);


        if(flujo == ' ' || flujo == '\n' || flujo == '\t' || flujo == EOF){
            stateOut(cc,vectorContador, cantContadores, file);
        }   else {
                ++cc;
                stateIn(cc, vectorContador, cantContadores, file);
            }

            flujo = getc(file);


}
  

void stateOut(unsigned cc, unsigned vectorContador[], int cantContadores, FILE* file){
    
    int flujo=getc(file);
    if(flujo==EOF){return;}
        if(flujo == ' ' || flujo == '\n' || flujo == '\t' || flujo == EOF){
            stateOut(cc, vectorContador, cantContadores, file);
        } else {
            if (flujo != EOF){
                ++cc;
                stateIn(cc, vectorContador, cantContadores, file);
            }
        }  
}

void stateIn(unsigned cc, unsigned vectorContador[], int cantContadores, FILE* file){
 
    int flujo = getc(file);
    if(flujo == ' ' || flujo == '\n' || flujo == '\t' || flujo == EOF){ 
        if (cc != 0){
            if(cc > cantContadores - 1){
                vectorContador[cantContadores-1]++;
                cc=0;
            }   else {
                    vectorContador[cc-1]++;
                    cc=0; 
                }
            if(flujo==EOF){return;}
        }
        stateOut(cc, vectorContador, cantContadores, file);

    }   else {
            ++cc;
            stateIn(cc, vectorContador, cantContadores, file);
        }
}