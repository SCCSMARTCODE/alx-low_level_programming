#include "main.h"
/**
 * print_diagonal -  draws a diagonal line on the terminal.
 *
 * @n: arguement
 *
 * Return: Void
 */
void print_diagonal(int n)
{

	int a, i;

	if (n > 0)
	{

	for (a = 0; a < n; a++)
	{
		for (i = 0; i < a; i++)
		{
			_putchar(32);
		}
		_putchar('\\');
		_putchar('\n');
	}
	}
	else
	{
		_putchar('\n');
	}
}
