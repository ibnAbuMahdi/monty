#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - pushes a node unto the list
 * @node: the node to push
 * @lno: line number
 */

void push(stack_t **node, unsigned int lno)
{
	if (*node == front)
	{
		fprintf(stderr, "L%u: usage: push integer\n", lno);
		exit(EXIT_FAILURE);
	}
	else if (*node)
	{
		add_dnodeint(&front, (*node)->n);
	}
}

/**
 * pall - print all nodes
 * @node: dummy node or head node
 * @lno: line number
 */

void pall(stack_t **node, unsigned int lno)
{
	(void) lno;

	if (*node)
		print_dlistint(front);
}

/**
 * pint - prints int at top of stack
 * @node: top node
 * @lno: the line number
 */

void pint(stack_t **node, unsigned int lno)
{
	(void) node;

	if (front)
	{
		printf("%d\n", front->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty", lno);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - pops node from list
 * @node: the node
 * @lno: line number
 */

void pop(stack_t **node, unsigned int lno)
{
	(void) node;

	if (front)
	{
		pop_dlistint(&front);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack", lno);
		exit(EXIT_FAILURE);
	}
}

/**
 * swap - swaps the top two nodes
 * @node: address of the node pointer
 * @lno: line number
 */

void swap(stack_t **node, unsigned int lno)
{
	(void) node;

	if (dlistint_len(front) > 1)
	{
		swap_dlistint(&front);
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short", lno);
		exit(EXIT_FAILURE);
	}
}
