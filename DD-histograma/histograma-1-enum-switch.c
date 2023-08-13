#include <stdio.h>
#include "graficador.h"
#include <ctype.h>

void cantidadDePalabrasPorSuLongitud (unsigned vectorContador[], int cantContadores ,FILE* file )
{
    int flujo;
    unsigned cc = 0;
    typedef enum {IN,OUT} State;
    State state = OUT;

    do
    {
        flujo = getc(file);
        switch (state) {
            case OUT:
                switch (flujo) //Si esta en OUT y recibe un caracter:  
                {
                case ' ':   //Se queda en OUT
                case '\n':
                case'\t':
                    break;
                default:   //Si es un no espaciador va a IN
                    ++cc;
                    state = IN;
                    break;
                }
                break;
            case IN:
                switch (flujo) //Si esta en IN y recibe un caracter
                {
                case ' ': 
                case '\n'://Si en IN leo un espaciador.
                case'\t':
                case EOF:
                    if(cc>cantContadores-1){cc=cantContadores;}
                    vectorContador[cc-1]++;
                    cc=0;
                    state=OUT;
                    break;
                default: //Si leo un no espaciador.
                    ++cc;
                    break;
                }
                break;
         }
    } while (flujo != EOF);
}
