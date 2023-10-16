#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * _strncat - concatenates two strings.
 *
 * @dest: first value
 *
 * @src: second value
 *
 * @n: third value
 *
 * Return: Pointer to the resulting string 'dest'
 */

char *_strncat(char *dest, char *src, int n)
{
	int dest_len = 0;
	int i;
	int src_len = 0;

	while (dest[dest_len] != '\0')
	dest_len++;

	while (src[src_len] != '\0')
	src_len++;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
	dest[dest_len] = src[i];
	dest_len++;
	}

	dest[dest_len] = '\0';

	return (dest);
}
