#include "sort.c"

int main() {
    int info, temp, temp_1;
    printf("enter info of first elem: ");
    scanf("%d", &info);
    stack* head;
    stack* head_2;
    stack_init(&head, info);
    while(temp != 7) {
        printf("0 - init, 1 - push, 2 - pop, 3 - print stack, 4 - size, 5 - delete stack, 6 - concatenate, 7 - exit\n");
        scanf("%d", &temp);
        if(temp == 0) {
            printf("enter info: ");
            scanf("%d", &info);
            stack_init(&head_2, info);
        }
        else if(temp == 1) {
            printf("which stack? [1/2]: ");
            scanf("%d", &temp_1);
            if(temp_1 == 1){
                printf("enter element info: ");
                scanf("%d", &info);
                element_push(&head, info);
            }
            else if(temp_1 == 2){
                printf("enter element info: ");
                scanf("%d", &info);
                element_push(&head_2, info);
            }
        }
        else if(temp == 2) {
            printf("which stack? [1/2]: ");
            scanf("%d", &temp_1);
            if(temp_1 == 1){
                element_pop(&head);
            }
            else if(temp_1 == 2){
                element_pop(&head_2);
            }
        }
        else if(temp == 3) {
            printf("which stack? [1/2]: ");
            scanf("%d", &temp_1);
            if(temp_1 == 1){
                stack_print(head);
            }
            else if(temp_1 == 2) {
                stack_print(head_2);
            }
        }
        else if(temp == 4) {
            printf("which stack? [1/2]: ");
            scanf("%d", &temp_1);
            if(temp_1 == 1){
                printf("%d\n", stack_size(head));
            }
            else if(temp_1 == 2) {
                printf("%d\n", stack_size(head_2));
            }
        }
        else if(temp == 5) {
            printf("which stack? [1/2]: ");
            scanf("%d", &temp_1);
            if(temp_1 == 1){
                stack_delete(&head);
            }
            else if(temp_1 == 2) {
                stack_delete(&head_2);
            }
        }
        else if(temp == 6) {
            stack_concatenate(&head, &head_2);
        }
        else {
            return 0;
        }
    }
}