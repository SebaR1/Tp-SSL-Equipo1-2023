
#include "scanner.h"
#include <ctype.h>
#include <stdio.h>

#define MAXTAMANIO 100

bool getNextToken(Token *t){
    char lexeme[MAXTAMANIO];

    int c, i, nextChar;

    
    while((lexeme[0] = c = getchar()) == ' ' || lexeme[0] == '\t') //Lee el lexema e ignora tabs y espacios
    lexeme[1] = '\0';
   

    if (c == EOF){ //Si encuentra un EOF termina y retorna false
        return false;
    }

    if (!isdigit(c) && c != '.' ){ // Si encuentra algo q no sea un dígito ni un punto es un operador y retorna true
        if(((lexeme[0] ) == '-') && (isdigit(lexeme[1] = getchar()))){
            i = 1;
            while(isdigit(lexeme[++i] = getchar())); // Si encuentra algo que sea un dígito empieza a guardar el número
            if (lexeme[i] == '.'){
            while (isdigit(lexeme[++i] = getchar())); // Si encuentra un número fraccionario después de un . lo guarda
            }
    

        lexeme[i] = '\0';
        t->type = Number; 
        t->val = atof(lexeme); //Convierte el char en un float
        //printf("NumeroNegativo: %s\n", lexeme);
        
        return true;
        }
        if(lexeme [1] == '\n');
        ungetc(lexeme[1],stdin);
        
        t->type = c;
        t->val = 0;
    
   
        
        //ungetc(lexeme[1],stdin);
        //printf("Operador: %c\n", c); // Imprimir el operador
        return true;
    }

    i = 0;

 
    while(isdigit(lexeme[++i] = c = getchar())); // Si encuentra algo que sea un dígito empieza a guardar el número
    if (c == '.'){
        while (isdigit(lexeme[++i] = c = getchar())); // Si encuentra un número fraccionario después de un . lo guarda
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
