#include "main.h"
#include <stdio.h>

/**
 * _strpbrk - locates the first occurrence of any byte from accept in the string s.
 *
 * @s: the string to search in
 * @accept: the set of bytes to search for
 *
 * Return: a pointer to the byte in s that matches one of the bytes in accept,
 * or NULL if no such byte is found.
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
