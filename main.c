#include "sort.c"

int main() {
    int info, temp, temp_1;
    printf("enter info of first elem: ");
    scanf("%d", &info);
    stack* head;
    stack_init(&head, info);
    while(temp != 7) {
        printf("1 - push, 2 - pop, 3 - print stack, 4 - size, 5 - delete stack, 6 - sort, 7 - exit\n");
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
        else if(temp == 5) {
            stack_delete(&head);
        }
        else if(temp == 6) {
            stack_sort(&head);
        }
        else {
            return 0;
        }
    }
}