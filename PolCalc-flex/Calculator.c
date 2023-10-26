#include <stdio.h>
#include "StackofDoublesModule.h"
#include "scanner.h"


extern bool yylex();
Token token;

int main (void){
    stackItem op1, resultado;
    while (yylex()){
        //printf("Token type: %c, Token val: %.2lf\n", token.type, token.val);
        switch(token.type){
            case Number:
                push(token.val);
                break;
            case '-':
                op1 = pop();
                push(pop() - op1);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '/':
                op1 = pop();
                if(op1 == 0){
                    printf("No se puede dividir por cero, por si no lo sabia...\n");
                    return 1;
                }
                push(pop() / op1);
                break;
            case '*':
                push(pop() * pop());
                break;
            case LexError:
                printf("Error lexico\n");
                return 1;
            case PopResult:
                resultado = pop();
                if (isEmpty()){
                    printf("El resultado es: %f\n", resultado);
                    return 0;
                }
                else {
                    printf("Faltan operadores o sobran digitos...\n");
                   return 1;
                }
        }
    }
    return 0;
}







