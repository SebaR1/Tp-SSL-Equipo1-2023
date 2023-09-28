
#include "scanner.h"
#include <ctype.h>
#include <stdio.h>

#define MAXTAMANIO 100
bool operadorValido(char);
bool getNextToken(Token *t){
    char lexeme[MAXTAMANIO];
    int c, i, nextChar;

    while((lexeme[0] = c = getchar()) == ' ' || lexeme[0] == '\t') //Lee el lexema e ignora tabs y espacios
   // lexeme[1] = '\0';
   

    if (c == EOF){ //Si encuentra un EOF termina y retorna false
        return false;
    }

    if (c == '\n'){
        t->type = PopResult;
        t->val = 0;
        return true;
    }

    if (!isdigit(c) && c != '.'){ // Si encuentra algo q no sea un dígito ni un punto es un operador y retorna true
        if(((lexeme[0] ) == '-') && (isdigit(lexeme[1] = getchar()))){
            i = 1;
            while(isdigit(lexeme[++i] = getchar())); // Si encuentra algo que sea un dígito empieza a guardar el número
            if (lexeme[i] == '.'){
            while (isdigit(lexeme[++i] = getchar())); // Si encuentra un número fraccionario después de un . lo guarda
                if(lexeme[i] == '.' || !isdigit(lexeme[i])){
                    t->type = LexError;
                    return true;
                }
            }
            if(!isdigit(lexeme[i]))
            ungetc(lexeme[i],stdin);
            lexeme[i] = '\0';
            t->type = Number; 
            t->val = atof(lexeme); //Convierte el char en un float
            return true;
        }

        if((lexeme [1] == '\n' && (c = getchar()) == EOF) || operadorValido(lexeme[1])){
            ungetc(lexeme[1],stdin);
        }

        if(operadorValido(lexeme[0])){
            t->type = lexeme[0];
            t->val = 0;
            return true;
        } else {
            t->type = LexError;
            return true;
        }
        
    }

    i = 0;
    while(isdigit(lexeme[++i] = c = getchar())); // Si encuentra algo que sea un dígito empieza a guardar el número
    if (c == '.'){
        while (isdigit(lexeme[++i] = c = getchar())); // Si encuentra un número fraccionario después de un . lo guarda
        if(lexeme[i] == '.' || !isdigit(lexeme[i])){
            t->type = LexError;
            return true;
        }
    }
    lexeme[i] = '\0';
    t->type = Number; 
    t->val = atof(lexeme); //Convierte el char en un float

    if(c != EOF){
        ungetc(c,stdin);
    }
    return true;
}

bool operadorValido(char lexeme){
//printf("%c\n",lexeme);
    if(lexeme == '-' || lexeme == '+' || lexeme == '/' || lexeme == '*'){
        return true;
    } else {
        
        return false;
    }
       
}