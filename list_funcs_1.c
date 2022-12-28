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
		{"pop", pop}, {"swap", swap}, {"nop", nop}, {"add", add}, {"sub", sub},
		{"div", _div}, {"mul", mul}, {"mod", mod}, {"pchar", pchar}, {"pstr", pstr},
		{"rotl", rotl}, {"rotr", rotr}};

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
 * add - adds the top two nodes
 * @node: address of the node pointer
 * @lno: the line number
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
 * nop - do nothing opcode
 * @node: address of the head pointer
 * @lno: the line number
 */

void nop(stack_t **node, unsigned int lno)
{
	(void) node;
	(void) lno;
}

/**
 *
 */

void sub(stack_t **node, unsigned int lno)
{
	(void) node;

	if (dlistint_len(front) > 1)
	{
		sub_dlistint(&front);
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", lno);
		exit(EXIT_FAILURE);
	}
}

/**
 *
 */

void _div(stack_t **node, unsigned int lno)
{
	(void) node;

	if (dlistint_len(front) > 1)
	{
		if (front->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", lno);
			exit(EXIT_FAILURE);
		}
		div_dlistint(&front);
	}
	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", lno);
		exit(EXIT_FAILURE);
	}
}

/**
 *
 */

void mul(stack_t **node, unsigned int lno)
{
	(void) node;

	if (dlistint_len(front) > 1)
	{
		mul_dlistint(&front);
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", lno);
		exit(EXIT_FAILURE);
	}

}

/**
 *
 */

void mod(stack_t **node, unsigned int lno)
{
	(void) node;

	if (dlistint_len(front) > 1)
	{
		if (front->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", lno);
			exit(EXIT_FAILURE);
		}
		mod_dlistint(&front);
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", lno);
		exit(EXIT_FAILURE);
	}
}

/**
 *
 */

void pchar(stack_t **node, unsigned int lno)
{
	(void) node;

	if (dlistint_len(front) > 0)
	{
		if (front->n < 128 && front->n > 0)
		{
			printf("%c\n", front->n);
		}
		else
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", lno);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", lno);
		exit(EXIT_FAILURE);
	}
}

/**
 *
 */

void pstr(stack_t **node, unsigned int lno)
{
	stack_t *temp = NULL;
	
	(void) node;
	(void) lno;
	temp = front;
	while (temp && (temp->n < 128 && temp->n > 0))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 *
 */

void rotl(stack_t **node, unsigned int lno)
{
	stack_t *first, *second, *last;
	
	(void) node;
	(void) lno;
	first = front;
	if (dlistint_len(front) > 1)
	{
		second = first->next;
		while (first->next)
		{
			last = first->next;
			first = first->next;
		}
		last->next = front;
		front->prev = last;
		front->next = NULL;
		front = second;
		front->prev = NULL;
	}
}

/**
 *
 */

void rotr(stack_t **node, unsigned int lno)
{
	stack_t *first, *sLast, *last;

	(void) node;
	(void) lno;
	if (dlistint_len(front) > 1)
	{
		first = front;
		last = front;
		while (last->next)
		{
			sLast = last;
			last = last->next;
		}
		sLast->next = NULL;
		last->next = first;
		first->prev = last;
		front = last;
		front->prev = NULL;
	}
}



