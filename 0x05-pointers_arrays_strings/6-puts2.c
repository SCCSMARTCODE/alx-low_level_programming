#include "main.h"
#include <stddef.h>

/**
 * puts2 - prints every other character of a string
 *
 * @str: Pointer to the string
 *
 * Return: void
 */
void puts2(char *str)
{
	int i = 0;

	if (str != NULL)
	{
	while (str[i] != '\0')
	{
	if (i % 2 == 0)
	_putchar(str[i]);
	i++;
	}
	_putchar('\n');
	}
}
