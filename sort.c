#include "funcs.c"

void stack_concatenate(stack** head_first, stack** head_second) {
    stack* temp = *head_second, *temp_empty;
    stack_init(&temp_empty, temp->info);
    element_pop(head_second);
    while(stack_size(*head_second)) {
        element_push(&temp_empty, temp->info);
        element_pop(head_second);
        temp = *head_second;
    }
    while(stack_size(temp_empty)) {
        element_push(head_first, temp_empty->info);
        element_pop(&temp_empty);
    }
}