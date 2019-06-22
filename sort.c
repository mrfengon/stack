#include "sort.h"

void stack_concatenate (stack** head_first, stack** head_second) {
    stack* temp;

    stack_init(&temp, (*head_second)->info);
    element_pop(head_second);

    while (!stack_empty(*head_second))
    {
        element_push(&temp, (*head_second)->info);
        element_pop(head_second);
    }

    while (!stack_empty(temp))
    {
        element_push(head_first, temp->info);
        element_pop(&temp);
    }
}

void stack_sort (stack** head) {
    stack* temp = *head;
    stack* less = NULL;
    stack* greater = NULL;

    int temp_el, key = temp->info;
    temp = element_pop(&temp);
    
    while (!stack_empty(temp)) {
        temp_el = temp->info;
        temp = element_pop(&temp);
        if(temp_el < key) {
            element_push(&less, temp_el);
        }
        else {
            element_push(&greater, temp_el);
        }
    }

    if(stack_size(less) > 1) {
        stack_sort(&less);
    }
    if(stack_size(greater) > 1) {
        stack_sort(&greater);
    }

    element_push(&less, key);

    if(!stack_empty(less) && !stack_empty(greater)){
        stack_concatenate(&less, &greater);
    }

    if(!stack_empty(less)) {
        *head = less;
        stack_delete(&greater);
    } else if(!stack_empty(greater)) {
        *head = greater;
        stack_delete(&less);
    }
}