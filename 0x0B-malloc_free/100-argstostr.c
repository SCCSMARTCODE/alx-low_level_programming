#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments of the program.
 * @ac: The argument count
 * @av: Array of arguments
 *
 * Return: A pointer to a newly allocated string.
 */
char *argstostr(int ac, char **av)
{
	int totalLength = 0;
	char *result;
	int i, j, k = 0;

	if (ac == 0 || av == NULL)
	return (NULL);

	for (i = 0; i < ac; i++)
	{
	for (j = 0; av[i][j]; j++)
	totalLength++;
	totalLength++; /* For the newline character */
	}
	result = (char *)malloc((totalLength + 1) * sizeof(char));
	if (result == NULL)
	return (NULL);
	for (i = 0; i < ac; i++)
	{
	for (j = 0; av[i][j]; j++)
	{
	result[k] = av[i][j];
	k++;
	}
	result[k] = '\n'; /* Add newline character */
	k++;
	}
	result[k] = '\0'; /* Null-terminate the concatenated string */
	return (result);
}
