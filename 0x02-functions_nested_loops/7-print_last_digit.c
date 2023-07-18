#include "main.h"

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

	if (no < 0)
	{
		no = -no;
	}

	ans = no % 10;

	_putchar(ans + '0');

	return (ans);
}
