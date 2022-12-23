#include "monty.h"
#include <stddef.h>

/**
 * get_func - executes the function that correspond to the opcode
 * @args: the list containing the opcode and the arg
 * @lno: the line number
 * Return: 1 on success and 0 o.w.
 */

int get_func(char **args, unsigned int lno)
{
	int i, size;
	stack_t *new_node = NULL;
	instruction_t inst[] = {{"pall", pall}, {"push", push}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"nop", nop}, {"add", add}};

	if (count(args) > 1)
	{
		new_node = malloc(sizeof(stack_t));
		if (!new_node)
			malloc_error();
	}
	size = sizeof(inst) / sizeof(inst[0]);
	for (i = 0; i < size; i++)
	{
		if (strcmp(args[0], inst[i].opcode) == 0)
		{
			if (count(args) > 1 && !contains_letter(args[1]))
			{
				new_node->n = atoi(args[1]);
				inst[i].f(&new_node, lno);
			}
			else
			{
				inst[i].f(&front, lno);
			}
			if (new_node)
				free(new_node);
			return (1);
		}
	}
	free(new_node);
	return (0);
}

/**
 *
 */

void add(stack_t **node, unsigned int lno)
{
	(void) node;

	if (dlistint_len(front) > 1)
	{
		add_dlistint(&front);
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", lno);
		exit(EXIT_FAILURE);
	}
}

/**
 *
 */

void nop(stack_t **node, unsigned int lno)
{
	(void) node;
	(void) lno;
}




