#ifndef STACK_OF_DOOBLES_MODULE_H
#define STACK_OF_DOOBLES_MODULE_H

#include <stdbool.h>

#define MAXVAL 100

typedef double stackItem;

bool isEmpty();
bool isFull();

void push(stackItem);

stackItem pop(void);

#endif