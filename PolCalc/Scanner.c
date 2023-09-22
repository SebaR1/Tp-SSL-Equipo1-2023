#include "Scanner.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#define TAM_BUFFER 10
#define SCANNER_H

enum TokenType {
 Number,
 Addition='+',
 Multiplication='*',
 Substraction='-',
 Division='/',
 PopResult='\n',
 LexError
};

typedef enum TokenType TokenType;
typedef double TokenValue;

struct Token{
 TokenType type;
 TokenValue val;
};

typedef struct Token Token;


void Scanner(FILE* c,Token *t){



    for(t;getNextToken(t)==true;){
        
    }


}
// 123.2 23 45 + -

bool getNextToken(Token *t){
int lexema,tam=TAM_BUFFER,i;  
char *buffer[TAM_BUFFER];

    if (isdigit(lexema=getchar())){
        for(i=1;((i < TAM_BUFFER) && ((isdigit(lexema=getchar())) || lexema == '.'));i++){
            buffer[i-1]=lexema;
        }
        buffer[++i] = '\0';

        if(isspace(lexema)){
            t->val = atof(buffer);
            t->type = Number;
            return true;
        } else { 
            t->type=LexError;
            return false;
        }
    }


}
