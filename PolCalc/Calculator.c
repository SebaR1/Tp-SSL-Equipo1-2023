#include <stdio.h>
#include "StackofDoublesModule.h"
#include "scanner.h"

int main (void){
    Token token;
    double op2;

    while ((getNextToken(&token)) != false){
        switch(token.type){
            case 'Number':
                push(token.val);
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
            default:
                printf("Error lexico, escriba bien los caracteres");
                return 1;
        }
    }
}








