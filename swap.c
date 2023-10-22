#include "monty.h"
void fun_swap(stack_t **head, unsigned int count) {
    int tmp;
    if (*head == NULL || (*head)->next == NULL) {
        fprintf(stderr, "L%d: can't swap, stack too short\n", count);
        cleanup_and_exit(head, EXIT_FAILURE);
    }
    
    tmp = (*head)->n;
    (*head)->n = (*head)->next->n;
    (*head)->next->n = tmp;
}
