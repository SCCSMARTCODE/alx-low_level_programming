#include "main.h"
#include <stdio.h>

/**
 * print_last_digit - print the last digit of a number.
 *
 * Return: int no
 *
 * @no: needed no
 */

int print_last_digit(int no)
{
	int ans;

	ans = no % 10;

	if (ans < 0)
	{
		ans = ans * -1;
	}

	_putchar(ans + '0');

	return (ans);
}
