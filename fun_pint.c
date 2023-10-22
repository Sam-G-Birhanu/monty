#include "monty.h"

void fun_pint(stack_t **head, unsigned int counter) {
    if (*head == NULL) {
        fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
        cleanup_and_exit(head, EXIT_FAILURE);
    }
    printf("%d\n", (*head)->n);
}

void cleanup_and_exit(stack_t **head, int status) {
    if (bus.file) {
        fclose(bus.file);
    }
    if (bus.content) {
        free(bus.content);
    }
    fun_free_stack(*head);
    exit(status);
}