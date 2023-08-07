#include <stdio.h>
#include "graficador.h"
#include "histograma.h"

//#define IMPLEMENTACION_1
//#define IMPLEMENTACION_2
//#define IMPLEMENTACION_3
#define IMPLEMENTACION_4

int main ()
{
    int i=0;
    unsigned cantidadDePalabras=0;
    enum {CANTIDAD_DE_CONTADORES=15};
    unsigned v[CANTIDAD_DE_CONTADORES]={0}; 

    

    #ifdef IMPLEMENTACION_1
    cantidadDePalabrasPorSuLongitud (v, CANTIDAD_DE_CONTADORES, stdin);
    dibujarHistograma(v, CANTIDAD_DE_CONTADORES);
    #endif
    #ifdef IMPLEMENTACION_2
    cantidadDePalabrasPorSuLongitud (v, CANTIDAD_DE_CONTADORES, stdin);
    dibujarHistograma(v, CANTIDAD_DE_CONTADORES);
    #endif 
    #ifdef IMPLEMENTACION_3
    cantidadDePalabrasPorSuLongitud (v, CANTIDAD_DE_CONTADORES, stdin);
    dibujarHistograma(v, CANTIDAD_DE_CONTADORES);
    #endif 
    #ifdef IMPLEMENTACION_4
    cantidadDePalabrasPorSuLongitud (v, CANTIDAD_DE_CONTADORES, stdin);
    dibujarHistograma(v, CANTIDAD_DE_CONTADORES);
    #endif 
  
}

