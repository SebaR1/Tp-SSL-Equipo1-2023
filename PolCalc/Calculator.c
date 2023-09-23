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
    }
}

}








