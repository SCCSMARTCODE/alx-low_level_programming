#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node at a specific index
 * @head: A pointer to a pointer to the head of the list.
 * @index: The index of the node to be deleted (starting at 0).
 * Return: 1 if the deletion succeeds, -1 if it fails
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i;
	dlistint_t *current;

	if (*head == NULL)
		return (-1); /* Return -1 if the list is empty */

	current = *head;

	/* If the node to be deleted is the head */
	if (index == 0)
	{
		*head = current->next; /* Update the head */
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current); /* Free the old head */
		return (1);
	}

	i = 0;

	while (i < index && current != NULL)
	{
		current = current->next;
		i++;
	}

	if (current == NULL)
		return (-1); /* Return -1 if the index is out of range */

	/* Remove the current node from the list */
	current->prev->next = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;

	free(current); /* Free the deleted node */
	return (1);
}

