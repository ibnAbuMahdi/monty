#ifndef MONTY_H
#define MONTY_H
#include <stddef.h>
#include <stdlib.h>

#define USAGE_ERROR 100
#define FILE_OPEN_ERROR 101

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

/* linked list front node */
extern stack_t *front;

#ifndef FRONT
stack_t *front;
#endif /* FRONT */

#include "general.h"
#include "text.h"

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

/**
 * struct error_s - error and its attributes
 * @msg: the error message
 * @code: the error code
 * @exit_code: the exit code
 */

typedef struct error_s
{
	char *msg;
	int code;
	int exit_code;
	char *file;
	char *opcode;
	int line_number;
} error_t;

/* print.c */
void print_err(error_t *);
void malloc_error();
void invalid_inst(char *, unsigned int);

/* list_funcs.c */
void pall(stack_t **, unsigned int);
void push(stack_t **, unsigned int);

/* main.c */
int process_args(char **, unsigned int, stack_t *);

#include "lists.h"

#endif /* MONTY_H */
