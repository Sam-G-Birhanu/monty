#include "monty.h"
/**
 * fun_push - add node to the stack
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
			if (b.arg[j] > 57 || b.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(b.file);
			free(b.content);
			fun_free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(b.file);
		free(b.content);
		fun_free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(b.arg);
	if (b.lifi == 0)
		fun_addnode(head, n);
	else
		fun_addqueue(head, n);
}
