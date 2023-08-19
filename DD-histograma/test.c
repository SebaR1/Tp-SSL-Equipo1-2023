#include <stdio.h>
#include <assert.h>
#include "histograma.h"
#include "graficador.h"
#include <stdbool.h> // Necesario para usar el tipo de dato 'bool'

bool verificarImplementacion() {
    enum {CANTIDAD_DE_CONTADORES = 15};
    unsigned v[CANTIDAD_DE_CONTADORES] = {0}, cantPalabrasImp=0;
    bool implementacion;
    // Abrir el archivo de prueba
    FILE *archivo = fopen("archivo_de_prueba.txt", "r");
    if (archivo == NULL) {
        perror("No se pudo abrir el archivo");
        return false; 
    }

    cantidadDePalabrasPorSuLongitud(v, CANTIDAD_DE_CONTADORES, archivo);
    dibujarHistograma(v, CANTIDAD_DE_CONTADORES);
    for (int i=0;i<CANTIDAD_DE_CONTADORES,i++;){
    cantPalabrasImp = v[i] + cantPalabrasImp;
    }

    assert (cantPalabrasImp!=4);

    fclose(archivo);


    implementacion = true;
    return implementacion;
}

int main() {

bool implementacion;

implementacion = verificarImplementacion();
    if (implementacion == true) {
        printf("Implementacion 1: Pruebas exitosas.\n");
    } else {
        printf("Implementacion 1: Pruebas fallidas.\n");
    }

    return 0;
}

