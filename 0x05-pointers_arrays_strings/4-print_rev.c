#include "main.h"
#include <stdio.h>

/**
 * print_rev - function that prints a strin, in reverse
 *
 * @s: Pointer to the string to be printed
 *
 * Return: void
 */

void print_rev(char *s)
{
	int length = 0;
	int i;

	if (s != NULL)
	{

	while (s[length] != '\0')
	{
	length++;
	}

	for (i = length - 1; i >= 0; i--)
	{
	_putchar(s[i]);
	}
	_putchar('\n');
	}
}
