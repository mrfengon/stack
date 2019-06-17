#include <stdio.h>
#include "funcs.h"
#include "stack.h"

int main() {
    int info, temp;
    printf("enter info of first elem: ");
    scanf("%d", &info);
    stack* root;
    stack_init(&root, info);
    while(temp != 4) {
        printf("\n1 - push, 2 - pop, 3 - print stack, 4 - exit\n");
        scanf("%d", &temp);
        if(temp == 1) {
            printf("enter element info: ");
            scanf("%d", &info);
            element_push(root, info);
        }
        else if(temp == 2) {
            element_pop(root);
        }
        else if(temp == 3) {
            stack_print(root);
        }
        else {
            return 0;
        }
    }
}