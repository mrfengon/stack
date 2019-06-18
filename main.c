#include <stdio.h>
#include "funcs.h"
#include "stack.h"

int main() {
    int info, temp;
    printf("enter info of first elem: ");
    scanf("%d", &info);
    stack* head;
    stack_init(&head, info);
    while(temp != 5) {
        printf("1 - push, 2 - pop, 3 - print stack, 4 - size, 5 - exit\n");
        scanf("%d", &temp);
        if(temp == 1) {
            printf("enter element info: ");
            scanf("%d", &info);
            element_push(&head, info);
        }
        else if(temp == 2) {
            element_pop(&head);
        }
        else if(temp == 3) {
            stack_print(head);
        }
        else if(temp == 4) {
            printf("%d\n", stack_size(head));
        }
        else {
            return 0;
        }
    }
}