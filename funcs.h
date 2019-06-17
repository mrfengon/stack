#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack* stack_init(stack** root, int info) {
    stack* temp = (stack*)(malloc(sizeof(stack)));
    temp->info = info;
    temp->next = NULL;
    *root = temp;
    return temp;
}

void element_push(stack* root, int info) {
    stack* temp = root;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    if(temp->next == NULL) {
        stack_init(&temp->next, info);
    }
}

void element_pop(stack* root) {
    stack* temp_1 = root, *temp_2 = temp_1->next;
    while(temp_2->next != NULL) {
        temp_1 = temp_2;
        temp_2 = temp_2->next;
    }
    if(temp_2->next == NULL) {
        temp_1->next = NULL;
    }
    free(temp_2);
}

void stack_print(stack* root) {
    stack* temp = root;
    while(temp->next != NULL) {
        printf("%d, ", temp->info);
        temp = temp->next;
    }
    if(temp->next == NULL) {
        printf("%d\n", temp->info);
        return;
    }
}