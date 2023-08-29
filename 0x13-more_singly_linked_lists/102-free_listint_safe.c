#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely.
 * @h: Pointer to the pointer of the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *temp, *current = *h;

	while (current != NULL)
	{
		count++;
		temp = current;
		current = current->next;
		free(temp);
		*h = NULL;

		if (temp <= current)
			break;
	}

	*h = NULL;
	return (count);
}

