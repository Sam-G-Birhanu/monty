#include "monty.h"
void fun_swap(stack_t **head, unsigned int counter) {
    int temp;
    if (*head == NULL || (*head)->next == NULL) {
        fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
        cleanup_and_exit(head, EXIT_FAILURE);
    }
    
    temp = (*head)->n;
    (*head)->n = (*head)->next->n;
    (*head)->next->n = temp;
}
