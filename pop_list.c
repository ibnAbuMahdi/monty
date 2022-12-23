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

/**
 * swap_dlistint - swap top two nodes
 * @head: the head node
 */

void swap_dlistint(stack_t **head)
{
	stack_t *temp = NULL;

	temp = (*head)->next;
	if (temp->next)
		temp->next->prev = *head;
	(*head)->next = temp->next;
	temp->next = *head;
	temp->prev = NULL;
	(*head)->prev = temp;
	*head = temp;
}

/**
 *
 */

void add_dlistint(stack_t **head)
{
	stack_t *temp;

	temp = *head;
	(*head)->next->n += (*head)->n;
	*head = temp->next;
	(*head)->prev = NULL;
	free(temp);
}



