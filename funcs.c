#include "funcs.h"

void stack_init(stack** head, int info) {
    stack* temp = (stack*)(malloc(sizeof(stack)));
    temp->info = info;
    temp->next = NULL;
    *head = temp;
}

bool stack_empty(stack* head) {
    return (head == NULL);
}

int stack_size(stack* head) {
    if (head == NULL) {
        return 0;
    }
    int size = 1;
    while(head != NULL && head->next != NULL) {
        size++;
        head = head->next;
    }
    return size;
}

void stack_delete(stack** head) {
    while(!stack_empty(*head)) {
        *head = element_pop(head);
    }
    printf("stack is deleted\n");
}

void element_push(stack** head, int info) {
    stack* new_head = (stack*)(malloc(sizeof(stack)));
    new_head->info = info;
    new_head->next = *head;
    *head = new_head;
}

stack* element_pop(stack** head) {
    if(stack_empty(*head)) {
        printf("stack is empty\n");
        return NULL;
    }
    stack* temp = *head;
    *head = temp->next;
    free(temp);
    return *head;
}

void stack_print(stack* head) {
    stack* temp = head;
    while(temp != NULL && temp->next != NULL) {
        printf("%d, ", temp->info);
        temp = temp->next;
    }
    if(temp != NULL && temp->next == NULL) {
        printf("%d\n", temp->info);
        return;
    }
}