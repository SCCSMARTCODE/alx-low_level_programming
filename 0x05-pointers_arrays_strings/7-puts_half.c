#include "main.h"
#include <stddef.h>

/**
 * puts_half - prints half of a string, followed by a new line
 *
 * @str: Pointer to the string
 *
 * Return: void
 */
void puts_half(char *str)
{
	int start;
	int length = 0;
	int i;


	if (str != NULL)
	{
	while (str[length] != '\0')
	{
	length++;
	}

	start = (length + 1) / 2;

	for (i = start; i < length; i++)
	{
	_putchar(str[i]);
	}

	_putchar('\n');
	}
}
