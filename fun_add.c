#include "monty.h"

void fun_add(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int result;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		cleanup_and_exit(head, EXIT_FAILURE);
	}
	temp = *head;
	result = temp->n + temp->next->n;
	temp->next->n = result;
	*head = (*head)->next;
	free(temp);
}
