#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	int damn_you;

	for (damn_you = 0; damn_you <= 9; damn_you++)
	{
		putchar(damn_you + '0');
	}

	putchar('\n');

	return (0);
}
