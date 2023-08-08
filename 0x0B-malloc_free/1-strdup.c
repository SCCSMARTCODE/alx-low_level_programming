#include "main.h"
#include <stdlib.h>


/**
 * _strdup - Duplicate a string using dynamic memory allocation
 * @str: The string to duplicate
 *
 * Return: A pointer to the newly allocated duplicate
 */

char *_strdup(char *str)
{
	int i;
	char *ptr;

	if (str == NULL)
	return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	continue;

	ptr = malloc((i + 1) * sizeof(char));

	if (ptr == NULL)
	return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	ptr[i] = str[i];

	ptr[i] = '\0';

	return (ptr);
}
