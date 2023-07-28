#include <stdio.h>
#include "main.h"

/**
 * rot13 - applies ROT13 substitution cipher to a string.
 * @str: input string
 *
 * Return: Pointer to the resulting string
 */


char *rot13(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
	if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
	{
	str[i] += 13;
	}
	else if ((str[i] >= 'n' && str[i] <= 'z') || (str[i] >= 'N' && str[i] <= 'Z'))
	{
	str[i] -= 13;
	}

	i++;
	}

	return (str);
}
