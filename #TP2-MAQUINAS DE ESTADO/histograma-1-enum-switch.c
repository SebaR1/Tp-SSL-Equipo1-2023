#include <stdio.h>

int main ()
{
    {
        typedef enum {IN,OUT} State;
        State state = OUT;
        int v[999];
        int c=0,i=0,cc;
       
        while ( c = getchar() != EOF )
        {
            switch (state)
                {
                case OUT:
                    switch (c) //Si esta en OUT y recibe un caracter:
                    {
                    case (" "||"\n"||"\t"):   //Se queda en OUT
                        break;

                    default:   //Si es un no espaciador va a IN
                        ++cc;
                        state = IN;
                    break;
                    }
                case IN:
                    switch (c) //Si esta en IN y recibe un caracter
                    {
                    case(" "||"\n"||"\t"): //Si en IN leo un espaciador.
                        v[i]=cc;
                        ++i;
                        cc=0;
                    
                    default: //Si leo un no espaciador.
                        ++cc;
                    break;
                    }
                }    
        }
    }
        
}





