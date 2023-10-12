#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given index
 * @h: A pointer to a pointer to the head of the list.
 * @idx: The index at which the new node should be inserted.
 * @n: The data to be stored in the new node.
 * Return: The address of the new node, or NULL on failure.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i = 0;
	dlistint_t *current = *h, *new;

	while (current != NULL)
	{
		if (i == idx)
		{
			new = malloc(sizeof(dlistint_t));
			if (new == NULL)
			{
				return (NULL);
			}
			new->n = n;
			if (i == 0)
			{
				new->prev = NULL;
				new->next = current;
				if (current != NULL)
				{
					current->prev = new;
				}
				*h = new;
			}
			else
			{
				new->prev = current->prev;
				new->next = current;
				current->prev->next = new;
				current->prev = new;
			}
			return (new);
		}
		i++;
		current = current->next;
	}
	if (i == idx)
	{
		return (add_dnodeint_end(h, n));
	}
	return (NULL);
}

