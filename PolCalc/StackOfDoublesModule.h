#ifndef STACK_OF_DOOBLES_MODULE_H
#define STACK_OF_DOOBLES_MODULE_H

#include <stdbool.h>

#define MAXVAL 100

bool isEmpty();
bool isFull();

void push(double token);

double pop(void);

#endif