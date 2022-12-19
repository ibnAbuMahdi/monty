#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pop_dlistint - pops the head node
 * @head: pointer to the head node
 * Return: n member of the node
 */

int pop_dlistint(stack_t **head)
{
	int i = 0;
	stack_t *temp = NULL;

	if (head)
	{
		if (*head)
		{
			temp = *head;
			i = temp->n;
			*head = temp->next;
			free(temp);

		}
	}
	return (i);
}
