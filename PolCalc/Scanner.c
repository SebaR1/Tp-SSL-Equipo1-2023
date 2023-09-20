#include "Scanner.h"
#include <stdio.h>
#include <stdbool.h>
#define TAM_BUFFER 10

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


bool getNextToken(Token *t){
int lexema, *buffer[TAM_BUFFER],tam=TAM_BUFFER,i=0;  

    for(TAM_BUFFER;(tam> 0,lexema=getchar());(--tam,++i)){
        if (isdigit(atof(lexema))){
            buffer[i]=lexema;
        }
    }
}