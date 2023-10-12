#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node to the end of a doubly linked list.
 * @head: A pointer to the head of the doubly linked list.
 * @n: The data to be stored in the new node.
 *
 * Return: A pointer to the new node, or NULL on failure.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t));

	if (new == NULL)
	{
		return (NULL); /* Return NULL on memory allocation failure */
	}

	new->n = n;
	new->next = NULL; /* The new node is the last, so its next should be NULL */

	if (*head == NULL)
	{
		/* If the list is empty, the new node becomes the head */
		new->prev = NULL;
		*head = new;
	}
	else
	{
		dlistint_t *tail = *head;

		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		/* Link the new node to the current tail */
		new->prev = tail;
		tail->next = new;
	}

	return new; /* Return the new node that was added to the end */
}

