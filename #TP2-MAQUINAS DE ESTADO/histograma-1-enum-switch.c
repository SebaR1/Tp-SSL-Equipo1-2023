#include <stdio.h>

int main (){


    {
        typedef enum {IN,OUT} State;
        State state = OUT;
        int v[999];
        int cc;
        int c=0;
       
        while ( c = getchar() != EOF ){
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
            }
                  
                }






        }
        
    }





}