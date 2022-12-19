#include "monty.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_dnodeint - adds a node to a linked list
 * @head: pointer to a node pointer
 * @n: the int n member of the node
 * Return: pointer to the added node;
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *temp = NULL;

	if (head)
	{
		temp = malloc(sizeof(stack_t));
		if (!temp)
			malloc_error();
		if (*head)
			(*head)->prev = temp;
		temp->next = *head;
		temp->prev = NULL;
		temp->n = n;
		*head = temp;
	}
	return (temp);
}



