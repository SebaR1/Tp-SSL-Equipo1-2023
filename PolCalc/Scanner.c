
#include "scanner.h"
#include <ctype.h>
#include <stdio.h>

#define MAXTAMANIO 100

bool getNextToken(Token *t){
    char lexeme[MAXTAMANIO];

    int c, i;

    while((lexeme[0] = c = getchar()) == ' ' || c == '\t') //Lee el lexema e ignora tabs y espacios
    lexeme[1] = '\0';

    if (c == EOF){ //Si encuentra un EOF termina y retorna false
        return false;
    }

    if (!isdigit(c) && c != '.'){ // Si encuentra algo q no sea un dígito ni un punto es un operador y retorna true
        t->type = c;
        t->val = 0;

    //    printf("Operador: %c\n", c); // Imprimir el operador
        return true;
    }

    i = 0;
    while(isdigit(lexeme[++i] = c = getchar())){; // Si encuentra algo que sea un dígito empieza a guardar el número
    if (c == '.'){
        while (isdigit(lexeme[++i] = c = getchar())); // Si encuentra un número fraccionario después de un . lo guarda
    }
    }

    lexeme[i] = '\0';
    t->type = Number; 
    t->val = atof(lexeme); //Convierte el char en un float

    //printf("Numero: %s\n", lexeme); // Imprimir el lexema leído
    

    if(c != EOF){
        ungetc(c,stdin);
    }

    return true;
}

/*while (isdigit(c)){
            while(isdigit(lexeme[++i] = c = getchar()));
            if (c == '.'){
                while (isdigit(lexeme[++i] = c = getchar()))
                ;
                t->type = Number;
                t->val = atof(lexeme);        

                return true;
            }
        }
        */
