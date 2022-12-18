#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * dlistint_len - prints elements of a listint_t list
 * @h: head node of the list
 * Return: number of elements in the list
 */

size_t dlistint_len(const stack_t *h)
{
	size_t i = 0;
	stack_t *temp = (stack_t *) h;

	if (temp)
	{
		if (temp->next && temp->prev)
		{
			while (temp->prev)
				temp = temp->prev;
			while (temp)
			{
				temp = temp->next;
				i++;
			}
		}
		else if (temp->next)
		{
			while (temp)
			{
				temp = temp->next;
				i++;
			}
		}
		else if (temp->prev)
		{
			while (temp)
			{
				temp = temp->prev;
				i++;
			}
		}
		else
		{
			temp = temp->next;
			i++;
		}
	}
	return (i);
}

