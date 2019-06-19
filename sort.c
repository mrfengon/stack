#include "sort.h"

void stack_concatenate (stack** head_first, stack** head_second) {
    stack* temp = *head_second, *temp_empty;
    stack_init(&temp_empty, temp->info);
    element_pop(head_second);
    temp = *head_second;
    while(!stack_underflow(temp)) {
        element_push(&temp_empty, temp->info);
        element_pop(head_second);
        temp = *head_second;
    }
    stack_delete(head_second);
    stack_delete(&temp);
    while(!stack_underflow(temp_empty)) {
        element_push(head_first, temp_empty->info);
        element_pop(&temp_empty);
    }
    stack_delete(&temp_empty);
}

