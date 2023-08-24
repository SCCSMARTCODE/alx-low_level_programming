#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees the memory allocated for a linked list.
 * @head: Pointer to the head of the list.
 */
void free_list(list_t *head)
{
	list_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current->str);
		free(current);
	}
}

