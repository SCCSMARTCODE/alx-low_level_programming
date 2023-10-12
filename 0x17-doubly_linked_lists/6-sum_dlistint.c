#include "lists.h"

/**
 * sum_dlistint - main
 * @head: pla 1
 * Return: nth node
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
