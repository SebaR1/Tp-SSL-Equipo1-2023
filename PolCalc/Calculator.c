#include <stdio.h>
#include "StackofDoublesModule.h"
#include "scanner.h"

int main (void){
    Token token;
    stackItem op1, resultado;
    while ((getNextToken(&token)) != false){
        printf("Token type: %c, Token val: %.2lf\n", token.type, token.val);
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
            case PopResult:
            resultado = pop();
                if (isEmpty())
                    printf("El resultado es: %f\n", resultado);
                else {
                    printf("Faltan operadores o sobran digitos...\n");
                   return 1;
                }
                break;
            default:
                printf("Error lexico el siguiente caracter es invalido: %c\n", token.type);
                return 1;
        }
    }
    return 0;
}







