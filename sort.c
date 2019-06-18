#include "sort.h"

void stack_concatenate(stack** head_first, stack* head_second) {
    stack* temp_empty;
    stack_init(&temp_empty, head_second->info);
    element_pop(&head_second);
    while(stack_size(head_second)) {
        element_push(&temp_empty, head_second->info);
        element_pop(&head_second);
    }
    free(head_second);
    while(stack_size(temp_empty)) {
        element_push(head_first, temp_empty->info);
        element_pop(&temp_empty);
    }
}