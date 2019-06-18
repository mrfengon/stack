#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"
#include "funcs.h"
#include "funcs.c"

void stack_concatenate(stack** head_first, stack** head_second) {
    stack* temp = *head_second, *temp_empty;
    stack_init(&temp_empty, temp->info);
    element_pop(&temp);
    while(stack_size(temp)) {
        element_push(&temp_empty, temp->info);
        element_pop(&temp);
    }
    while(stack_size(temp_empty)) {
        element_push(head_first, temp_empty->info);
        element_pop(&temp_empty);
    }
}