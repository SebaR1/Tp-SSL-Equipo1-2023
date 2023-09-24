#include <stdio.h>
#include "StackofDoublesModule.h"
#include "scanner.h"

int main (void){
    Token token;
    double op2;

    while ((getNextToken(&token)) != false){
        //printf("Token type: %c, Token val: %.2lf\n", token.type, token.val);
        switch(token.type){
            case Number:
                push(token.val);
                //printf("Entro a pushear");
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                push(pop() / op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case PopResult:
                printf("El resultado es: %.2lf\n", pop());
                //printf("entro a popresult");
                break;
            default:
                printf("Error lexico, escriba bien los caracteres\n");
                return 1;
        }
    }
    return 0;
}







