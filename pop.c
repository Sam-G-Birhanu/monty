void fun_pop(stack_t **head, unsigned int counter) {
    if (*head == NULL) {
        fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
        cleanup_and_exit(EXIT_FAILURE);
    }

    stack_t *temp = *head;
    *head = (*head)->next;
    free(temp);
}
