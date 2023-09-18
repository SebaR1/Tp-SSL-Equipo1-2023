#include "Scanner.h"
#include <stdio.h>
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

bool GetNextToken(struct Token *t /*out*/); // Retorna si pudo leer, almacena en t el token leido. 

void Scanner(FILE* c, Token *t){
int flujo;
int buffer[TAM_BUFFER];
    while (flujo=getchar(c)!=EOF)

}