#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (success)
 */

int main(void)
{

	char low;
	char up;

	for (low = 'a'; low <= 'z'; low++)
	{
		putchar(low);
	}

	for (up = 'A'; up <= 'Z'; up++)
	{
		putchar(up);
	}

	putchar('\n');

	return (0);
}
