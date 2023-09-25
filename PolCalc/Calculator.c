#include <stdio.h>
#include "StackofDoublesModule.h"
#include "scanner.h"

int main (void){
    Token token;
    stackItem op2=0, op1=0;
    while ((getNextToken(&token)) != false){
        printf("Token type: %c, Token val: %.2lf\n", token.type, token.val);
        switch(token.type){
            case Number:
                push(token.val);
                //printf("Entro a pushear");
                break;
            case '-':
            //printf("Token type: %c\n", token.type);
                op1 = pop();
                push(pop() - op1);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '/':
                op2 = pop();
                if(op2 == 0){
                    printf("No se puede dividir por cero, por si no lo sabia...");
                    return 1;
                }
                push(pop() / op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case PopResult:
                printf("El resultado es: %f\n", pop());
                //printf("entro a popresult");
                break;
            default:
                printf("Error lexico el siguiente caracter es invalido: %c\n", token.type);
                return 1;
        }
    }
    return 0;
}







