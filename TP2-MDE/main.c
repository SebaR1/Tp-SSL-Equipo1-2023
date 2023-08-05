#include <stdio.h>
#include "histograma.h"
#include "graficador.h"

int main ()
{
    int i=0;
    unsigned cantidadDePalabras=0;

        enum {CANTIDAD_DE_CONTADORES=15};
        unsigned v[CANTIDAD_DE_CONTADORES]={0};       
        
    cantidadDePalabrasPorSuLongitud (v, CANTIDAD_DE_CONTADORES, stdin);
    dibujarHistograma(v, CANTIDAD_DE_CONTADORES);

  
}



