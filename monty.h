#ifndef MONTY_HEADER
#define MONTY_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
typedef struct b_s
{
	char *arg;
	FILE *file;
	char *cont;
	int lifi;
}  b_t;
extern b_t b;
/** void fun_push(stack_t **head, unsigned int number); **/
void fun_push(stack_t **head, unsigned int count);
void fun_pall(stack_t **head, unsigned int number);
void fun_pint(stack_t **head, unsigned int number);

void cleanup_and_exit(stack_t **head, int status);
void fun_addnode(stack_t **head, int n);
void fun_addqueue(stack_t **head, int n);
void fun_free_stack(stack_t *head);
int fun_exec(char *cont, stack_t **head, unsigned int count, FILE *file);
void fun_pop(stack_t **head, unsigned int count);
void fun_swap(stack_t **head, unsigned int count);
void fun_add(stack_t **head, unsigned int count);
void fun_sub(stack_t **head, unsigned int counter);
void fun_div(stack_t **head, unsigned int counter);
void fun_mul(stack_t **head, unsigned int counter);
void fun_mod(stack_t **head, unsigned int counter);

void fun_nop(stack_t **head, unsigned int count);


#endif
