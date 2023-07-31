#include <stdio.h>
#include "main.h"

/**
 * _memset - fills memory with a constant byte
 *
 * @s: parameter1
 * @b: parameter2
 * @n: parameter3
 *
 * Return: *s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		s[i] = b;

		i++;
	}

	return (s);
}
