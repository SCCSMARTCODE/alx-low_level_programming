#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	int i;
	char putch[10] = "_putchar";

	for (i = 0; i < 8; i++)
	{
		putchar(putch[i]);
		putchar('\n');
	}

	return (0);
}
