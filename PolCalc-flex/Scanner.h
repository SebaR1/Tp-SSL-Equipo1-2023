#ifndef SCANNER_H
#define SCANNER_H

#include <stdbool.h>
#include <stdlib.h>

enum TokenType {
    Number,
    Addition='+',
    Multiplication='*',
    Substraction='-',
    Division='/',
    PopResult='\n',
    LexError,
    Space=' '
};
typedef enum TokenType TokenType;
typedef double TokenValue;

struct Token{
 TokenType type;
 TokenValue val;
};
typedef struct Token Token;

#endif