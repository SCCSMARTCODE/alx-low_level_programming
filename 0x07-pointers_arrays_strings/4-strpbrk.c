#include "main.h"
#include <stdio.h>

/**
 * _strpbrk - locates the first occurrence..
 *
 * @s: the string to search in
 * @accept: the set of bytes to search for
 *
 * Return: a pointer to
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
	for (j = 0; accept[j] != '\0'; j++)
	{
	if (s[i] == accept[j])
	{
	return (s + i);
	}
	}
	}

	return (NULL);
}
