#include "monty.h"

void fun_add(stack_t **head, unsigned int counter) {
    stack_t *temp;
    if (*head == NULL || (*head)->next == NULL) {
        fprintf(stderr, "L%d: can't add, stack too short\n", counter);
        cleanup_and_exit(head, EXIT_FAILURE);
    }

    temp = *head;
    int result = temp->n + temp->next->n;
    temp->next->n = result;
    *head = (*head)->next;
    free(temp);
}
