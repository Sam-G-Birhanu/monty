#include "monty.h"
/**
* fun_exec - executes the opcode
* @stack: head linked list - stack
* @count: line_count
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int fun_exec(char *content, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opst[] = {
				{"push", fun_push}, {"pall", fun_pall}, {"pint", fun_pint},
	{"pop", fun_pop},
	{"swap", fun_swap},
	{"add", fun_add},
	{"sub", fun_sub},
	{"div", fun_div},
	{"mul", fun_mul},
	{"mod", fun_mod},
	{"nop", fun_nop},
	{"pchar", f_pchar},
	{"pstr", f_pstr},
	{"rotl", f_rotl},
	{"rotr", f_rotr},
	{"queue", f_queue},
	{"stack", f_stack},
	{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	b.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(content);
		fun_free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

