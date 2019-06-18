#ifndef FUNCS_H
#define FUNCS_H

void stack_init(stack** head, int info);
_Bool stack_underflow(stack* head);
size_t stack_size(stack* head);
void stack_delete(stack** head);
void element_push(stack** head, int info);
stack* element_pop(stack** head);
void stack_print(stack* head);

#endif