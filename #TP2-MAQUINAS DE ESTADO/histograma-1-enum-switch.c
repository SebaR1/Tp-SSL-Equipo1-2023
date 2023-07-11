#include <stdio.h>
#include "histograma.h"

void cantidadDePalabrasPorSuLongitud (unsigned vectorContador[], int cantContadores ,FILE *c )
{
    char flujo;
    unsigned cc = 0;
    typedef enum {IN,OUT} State;
    State state = OUT;

    while (  (flujo = getc(c)) != "\0" )
    {
        switch (state)
        {
            case OUT:
                switch (flujo) //Si esta en OUT y recibe un caracter:
                {
                case (' '||'\n'||'\t'):   //Se queda en OUT
                    break;

                default:   //Si es un no espaciador va a IN
                    ++cc;
                    state = IN;
                break;
                }
                case IN:
                switch (flujo) //Si esta en IN y recibe un caracter
                {
                    case(' '||'\n'||'\t'): //Si en IN leo un espaciador.
                    vectorContador[cc]++;
                    cc=0;
                    
                    default: //Si leo un no espaciador.
                    ++cc;
                    break;
                }
         }    
    }
}