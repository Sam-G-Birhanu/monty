#include "monty.h"

void fun_pint(stack_t **head, unsigned int count) {
    if (*head == NULL) {
        fprintf(stderr, "L%u: can't pint, stack empty\n", count);
        cleanup_and_exit(head, EXIT_FAILURE);
    }
    printf("%d\n", (*head)->n);
}

void cleanup_and_exit(stack_t **head, int status) {
    if (b.file) {
        fclose(b.file);
    }
    if (b.cont) {
        free(b.cont);
    }
    fun_free_stack(*head);
    exit(status);
}
