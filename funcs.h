#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

void stack_init(stack** head, int info) {
    stack* temp = (stack*)(malloc(sizeof(stack)));
    temp->info = info;
    temp->next = NULL;
    *head = temp;
}

bool stack_underflow(stack* head) {
    return (head == NULL);
}

size_t stack_size(stack* head) {
    size_t size = 0;
    stack* temp = head;
    while(temp->next != NULL) {
        size++;
        temp = temp->next;
    }
    if(temp->next == NULL) {
        size++;
    }
    return size;
}

void stack_delete(stack** head) {
    
}

void element_push(stack** head, int info) {
    stack* new_head = (stack*)(malloc(sizeof(stack*)));
    new_head->info = info;
    new_head->next = *head;
    *head = new_head;
}

void element_pop(stack** head) {
    if(stack_underflow(*head)) {
        printf("stack is underflow\n");
        return;
    }
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