#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "monty.h"

/**
 * print_dlistint - prints elements of a listint_t list
 * @h: head node of the list
 * Return: number of elements in the list
 */

size_t print_dlistint(const stack_t *h)
{
	size_t i = 0;
	stack_t *temp = (stack_t *) h;

	if (temp)
	{
		if (temp->next)
		{
			while (temp)
			{
				printf("%d\n", temp->n);
				temp = temp->next;
				i++;
			}
		}
		else if (temp->prev)
		{
			while (temp)
			{
				printf("%d\n", temp->n);
				temp = temp->prev;
				i++;
			}
		}
		else
		{
			printf("%d\n", temp->n);
			temp = temp->next;
			i++;
		}
	}
	return (i);
}

