#include "main.h"

/**
 * print_line -  draws a straight line in the terminal.
 *
 * @n: arguement
 *
 * Return: void
 */

void print_line(int n)
{
	int a;
	int b = 95;

	if (n > 0)
	{
	for (a = 0; a < n; a++)
	{
		_putchar(b);
	}
	_putchar('\n');
	}

	else
	{
		_putchar('\n');
	}
}
