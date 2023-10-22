#include "monty.h"
/**
 * fun_pint - prints in order
 * @head: stack head
 * @count: keep count
 * Return: none
 */

void fun_pint(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		cleanup_and_exit(head, EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * cleanup_and_exit - cleans
 * @head: stck head
 * @status: int status
 * Return: none
 */

void cleanup_and_exit(stack_t **head, int status)
{
	if (b.file)
	{
		fclose(b.file);
	}
	if (b.cont)
	{
		free(b.cont);
	}
	fun_free_stack(*head);
	exit(status);
}
