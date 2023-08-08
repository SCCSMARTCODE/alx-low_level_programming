#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenate two strings
 * @s1: The first string
 * @s2: The second string
 *
 * Return: A pointer to a newly allocated string conta
 */
char *str_concat(char *s1, char *s2)
{
	char *str;
	int i, j, n, m, totalLength;

	if (s1 == NULL || s2 == NULL)
	return (NULL);

	/* Calculate lengths of the input strings */
	for (i = 0; s1[i] != '\0'; i++)
	continue;
	for (j = 0; s2[j] != '\0'; j++)
	continue;

	totalLength = i + j + 1;
	str = malloc(totalLength * sizeof(char));
	if (str == NULL)
	return (NULL);

	/* Copy the contents of s1 to the new string */
	for (n = 0; n < i; n++)
	str[n] = s1[n];

	/* Copy the contents of s2 to the new string */
	for (m = 0; m < j; m++)
	str[i + m] = s2[m];

	/* Add the null-terminator at the end */
	str[totalLength - 1] = '\0';

	return (str);
}
