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

void stack_sort (stack** head) {
    stack* temp = *head, *less, *greater;
    int temp_el, key = temp->info;
    temp = element_pop(&temp);
    less = (stack*)(malloc(sizeof(stack*)));
    less = NULL;
    greater = (stack*)(malloc(sizeof(stack*)));
    greater = NULL;
    while(!stack_underflow(temp)) {
        temp_el = temp->info;
        temp = element_pop(&temp);
        if(temp_el < key) {
            element_push(&less, temp_el);
        }
        else {
            element_push(&greater, temp_el);
        }
    }
    if(!stack_underflow(less)) {
        if(stack_size(less) > 1) {
            stack_sort(&less);
        }
    }
    if(!stack_underflow(greater)) {
        if(stack_size(greater) > 1) {
            stack_sort(&greater);
        }
    }
    element_push(&less, key);
    if(!stack_underflow(less) && !stack_underflow(greater)){
        stack_concatenate(&less, &greater);
    }
    if(!stack_underflow(less)) {
        temp = less;
    }
    if(!stack_underflow(greater)) {
        temp = greater;
    }
    stack_delete(&less);
    stack_delete(&greater);
    *head = temp;
    stack_delete(&temp);
}