#include "main.h"

/**
 * _strlen_recursion - returns the length of a string using recursion.
 * @s: The input string.
 *
 * Return: The length of the string.
 */

int _strlen_recursion(char *s)
{
	int n = 0;

	if (*s == '\0')
	{
	return (n);
	}
	n = 1 + _strlen_recursion(s + 1);
	return (n);
}
