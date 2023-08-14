#include <stdio.h>
#include "graficador.h"
#include "histograma.h"
#include <string.h>

void limpiarbuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main ()
{
    int i=0;
    unsigned cantidadDePalabras=0;
    enum {CANTIDAD_DE_CONTADORES=15};
    unsigned v[CANTIDAD_DE_CONTADORES]={0}; 
    
    char buffer[10];

    printf("Ingresa el texto de prueba:\n");
    fgets(buffer, sizeof(buffer), stdin); // Leer el texto desde la consola
    limpiarbuffer();
    printf("leiste: %s", buffer);

    cantidadDePalabrasPorSuLongitud(v, CANTIDAD_DE_CONTADORES, stdin);
    //dibujarHistograma(v, CANTIDAD_DE_CONTADORES);
}

