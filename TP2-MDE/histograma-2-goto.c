#include <stdio.h>
#include "histograma.h"

void cantidadDePalabrasPorSuLongitud (unsigned vectorContador[], int cantContadores ,FILE* file )
{
    int flujo;
    unsigned cc = 0;

    while (  (flujo = getc(file)) != EOF ){
        if(flujo == ' ' || flujo == '\n' || flujo == '\t' ) goto out;
        else goto in;

        out: if(cc != 0){
            if(cc > cantContadores - 1) {cc = cantContadores;}
            
            vectorContador[cc - 1]++;
            cc = 0;
        }
        continue;
        in: cc++;   
    }   
}