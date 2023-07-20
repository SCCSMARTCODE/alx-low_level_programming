#include "main.h"

/**
 * print_most_numbers -  prints most numbers, from 0 to 9
 *
 * Return: void
 */

void print_most_numbers(void)
{
	int no;

	for (no = 0; no <= 9; no++)
	{

		if (no == 2 || no == 4)
		{

			continue;
		}

		_putchar(no + '0');

	}

	_putchar('\n');
}
