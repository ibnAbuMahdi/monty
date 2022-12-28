#include "monty.h"
#include <stdio.h>

/**
 *
 */

void mul_dlistint(stack_t **head)
{	
	stack_t *temp = NULL;

	temp = *head;
	(*head)->next->n *= (*head)->n;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}

/**
 *
 */

void mod_dlistint(stack_t **head)
{
	stack_t *temp = NULL;

	temp = *head;
	(*head)->next->n %= (*head)->n;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}
