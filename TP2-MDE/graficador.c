#include <stdio.h>
#include "graficador.h"

void dibujarHistograma(unsigned vectorContador[],unsigned cantidadDePalabras, int cantContadores ){
    int i=0,j=0;

    for (i;i<cantContadores;i++){
        if (i!=14){printf("i = %2d \n",i+1);}
            else {printf("i >= %2d \n",i+1); }
        
        for(j=0; j < vectorContador[i]; j++){
            printf("*");
        }
        printf("\n");
    }
}