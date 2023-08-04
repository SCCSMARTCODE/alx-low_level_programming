#include "main.h"
#include <stdio.h>

/**
 * _strstr - finds the first occurrence of the substring needle
 *
 * @haystack: the string to search in
 * @needle: the substring to search for
 *
 * Return: a pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	if (*needle == '\0')
	return (haystack);

	for (i = 0; haystack[i] != '\0'; i++)
	{
	j = 0;

	while (needle[j] != '\0' && haystack[i + j] == needle[j])
	j++;

	if (needle[j] == '\0')
	return (haystack + i);
	}

	return (NULL);
}
