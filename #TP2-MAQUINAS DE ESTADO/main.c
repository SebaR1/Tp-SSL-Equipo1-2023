#include <stdio.h>
#include "histograma.h"
int main ()
{
    

        enum {CANTIDAD_DE_CONTADORES=15};
        unsigned v[CANTIDAD_DE_CONTADORES]={0};       
        
    cantidadDePalabrasPorSuLongitud ( v, CANTIDAD_DE_CONTADORES, stdin);
    //dibujarHistograma(vectorConContadores)
}



