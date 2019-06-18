#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack* stack_init(stack** head, int info) {
    stack* temp = (stack*)(malloc(sizeof(stack)));
    temp->info = info;
    temp->next = NULL;
    *head = temp;
    return temp;
}

void element_push(stack** head, int info) {
    stack* new_head = (stack*)(malloc(sizeof(stack*)));
    new_head->info = info;
    new_head->next = *head;
    *head = new_head;
}

void element_pop(stack** head) {
    stack* temp = *head;
    *head = temp->next;
    free(temp);
}

void stack_print(stack* head) {
    stack* temp = head;
    while(temp->next != NULL) {
        printf("%d, ", temp->info);
        temp = temp->next;
    }
    if(temp->next == NULL) {
        printf("%d\n", temp->info);
        return;
    }
}