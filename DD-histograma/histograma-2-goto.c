#include <stdio.h>
#include "graficador.h"
#include <ctype.h>

void cantidadDePalabrasPorSuLongitud (unsigned vectorContador[], int cantContadores ,FILE* file )
{
    int flujo;
    unsigned cc = 0;

    do  {
        flujo = getc(file);
        if(isspace(flujo) != 0) goto out;
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
