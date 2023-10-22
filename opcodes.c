#include "monty.h"

/**
*fun_push - add node to the stack
* @head: stack head
* @count: line_number
* Return: no return
*/
void fun_push(stack_t **head, unsigned int count)
{
	int n, j = 0, flag = 0;

	if (b.arg)
	{
		if (b.arg[0] == '-')
			j++;
		for (; b.arg[j] != '\0'; j++)
		{
			if (b.arg[j] > '9' || b.arg[j] < '0')
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(b.file);
			free(b.cont);
			fun_free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(b.file);
		free(b.cont);
		fun_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(b.arg);
	if (b.lifi == 0)
		fun_addnode(head, n);
	else
		fun_addqueue(head, n);
}
/**
 * fun_pop - pops elts
 * @head: stack head
 * @count: stack counter
 * Return: return none
 */

void fun_pop(stack_t **head, unsigned int count)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		cleanup_and_exit(head, EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
/**
 * fun_swap - swaps
 * @head: stack head
 * @count: stack counter
 * Return: void
 */

void fun_swap(stack_t **head, unsigned int count)
{
	int tmp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		cleanup_and_exit(head, EXIT_FAILURE);
	}
	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}

/**
* fun_pall - prints the stack
* @head: stack head
* @count: no used
* Return: no return
*/
void fun_pall(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
/**
 * fun_nop - nop
 * @head: stack head
 * @counter: stack counter
 * Return: void
 */
void fun_nop(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
}
