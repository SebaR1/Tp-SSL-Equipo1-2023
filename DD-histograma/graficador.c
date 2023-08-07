#include <stdio.h>
#include "graficador.h"
int maximoVector (unsigned vectorContador[], int cantContadores);
void dibujarHistograma(unsigned vectorContador[], int cantContadores ){
    int i=0,j=0,k=0;
    int mayorCantPalabras = maximoVector(vectorContador, cantContadores); //maximoVector(vectorContador, cantContadores);
        
    for (i = 0; i < cantContadores; i++) {
            if (i != 14) {
                printf("%2d ", i + 1);
            } else {
                printf("15 =< ");
            }
    }
    printf("\n");

    for (k = 0  ; k < mayorCantPalabras; k++){
        for (j = 0; j < cantContadores; j++) {
            if(vectorContador[j] > k){
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }     
}
    



int maximoVector (unsigned vectorContador[], int cantContadores){
    int maximo = vectorContador[0];
     
    for (int i = 1; i < cantContadores; i++) {
        if (vectorContador[i] > maximo) {
            maximo = vectorContador[i]; 
        }
    }

return maximo;
}
