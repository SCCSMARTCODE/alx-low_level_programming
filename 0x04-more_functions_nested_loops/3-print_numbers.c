#include "main.h"

/**
 * print_numbers -  prints the numbers, from 0 to 9
 *
 * Return: void
 */

void print_numbers(void)
{
	int no;

	for (no = 0; no <= 9; no++)
	{
		_putchar(no + '0');
	}

	_putchar('\n');
}
