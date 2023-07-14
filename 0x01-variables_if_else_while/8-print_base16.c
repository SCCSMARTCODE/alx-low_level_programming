#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	int y0u;
	int you;

	for (y0u = 0; y0u <= 9; y0u++)
	{
		putchar(y0u + '0');
	}

	for (you = 'a'; you <= 'f'; you++)
	{
		putchar(you);
	}

	putchar('\n');

	return (0);
}
