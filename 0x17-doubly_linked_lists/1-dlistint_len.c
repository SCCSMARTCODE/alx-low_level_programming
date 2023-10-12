#include <stdio.h>
#include "lists.h"


/**
 * dlistint_len - main prororo
 * @h: pla 1
 * Return: i always
 */
size_t dlistint_len(const dlistint_t *h)
{
	int i = 0;

	while (h != NULL)
	{
		h = h->next;
		i++;
	}
	return (i);
}
