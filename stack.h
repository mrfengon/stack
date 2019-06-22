#ifndef STACK_H
#define STACK_H

typedef struct stack {
    int info;
    struct stack* next;
} stack;

#endif