#include "monty.h"
void fun_pop(stack_t **head, unsigned int counter) {
    stack_t *temp;
    if (*head == NULL) {
        fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
        cleanup_and_exit(head, EXIT_FAILURE);
    }

    temp = *head;
    *head = (*head)->next;
    free(temp);
}
