#include "lists.h"

/**
 * reverse_listint - Reverses a linked list.
 * @head: A pointer to the pointer to the first node in the list.
 *
 * Return: A pointer to the first node in the new list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev_node = NULL;
	listint_t *next_node = NULL;

	while (*head != NULL)
	{
		next_node = (*head)->next;
		(*head)->next = prev_node;
		prev_node = *head;
		*head = next_node;
	}

	*head = prev_node;

	return (*head);
}

