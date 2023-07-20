#include "main.h"

/**
 * more_numbers -  prints numbers, from 0 to 14
 *
 * Return: void
 */

void more_numbers(void)
{
	int a, i;

	for (a = 0; a < 10; a++)
	{
		for (i = 0; i <= 14; i++)
		{
			if (i > 9)
			{

				_putchar((i / 10) + '0');
			}
			_putchar((i % 10) + '0');
		}

		_putchar('\n');
	}

}
