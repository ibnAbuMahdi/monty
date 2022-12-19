#include "monty.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_dnodeint_end - adds a node to the end of linked list
 * @head: pointer to a node pointer
 * @n: the n member of the node
 * Return: pointer to the added node;
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *temp = NULL;

	if (head)
	{
		stack_t *temp1 = *head;

		if (*head)
		{
			while (temp1->next)
				temp1 = temp1->next;
		}
		temp = malloc(sizeof(stack_t));
		if (!temp)
			malloc_error();
		if (temp)
		{
			temp->next = NULL;
			temp->prev = NULL;
			temp->n = n;
			if (temp1)
			{
				temp1->next = temp;
				temp->prev = temp1;
			}
			else
			{
				*head = temp;
			}
		}
	}
	return (temp);
}



