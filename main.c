#include "monty.h"

b_t b = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: args
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *cont;
	FILE *file;
	size_t size = 0;
	ssize_t rd_ln = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	b.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (rd_ln > 0)
	{
		cont = NULL;
		rd_ln = getline(&cont, &size, file);
		b.cont = cont;
		count++;
		if (rd_ln > 0)
		{
			fun_exec(cont, &stack, count, file);
		}
		free(cont);
	}
	fun_free_stack(stack);
	fclose(file);
return (0);
}

