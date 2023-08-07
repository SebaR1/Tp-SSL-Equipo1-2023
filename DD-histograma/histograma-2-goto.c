#include <stdio.h>
#include "graficador.h"

#define IMPLEMENTACION_2
void cantidadDePalabrasPorSuLongitud (unsigned vectorContador[], int cantContadores ,FILE* file )
{
    int flujo;
    unsigned cc = 0;

    do  {
        flujo = getc(file);
        if(flujo == ' ' || flujo == '\n' || flujo == '\t' || flujo == EOF) goto out;
        else goto in;

        out: if(cc != 0){
                if(cc > cantContadores - 1) {cc = cantContadores;}
                
                vectorContador[cc - 1]++;
                cc = 0;
            }
        continue;
            in: cc++;   
    } while (flujo != EOF);
}


#undef IMPLEMENTACION_2