#include <stdio.h>
#include "graficador.h"
#include "histograma.h"

int main ()
{
    int i=0;
    unsigned cantidadDePalabras=0;
    enum {CANTIDAD_DE_CONTADORES=15};
    unsigned v[CANTIDAD_DE_CONTADORES]={0}; 
    int flujo = gets()

    cantidadDePalabrasPorSuLongitud (v, CANTIDAD_DE_CONTADORES, stdin);
    dibujarHistograma(v, CANTIDAD_DE_CONTADORES);
}

