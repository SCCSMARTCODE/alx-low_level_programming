#include "main.h"

/**
 * more_numbers -  prints numbers, from 0 to 14
 *
 * Return: void
 */

void more_numbers(void)
{
	int i;

	for (i = 0; i <= 14; i++)
	{
		_putchar(i + '0');
		_putchar('\n');
	}

	_putchar('\n');
}
