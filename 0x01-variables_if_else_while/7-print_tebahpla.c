#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	int minu;

	for (minu = 'z'; minu >= 'a'; minu--)
	{
		putchar(minu);
	}

	putchar('\n');

	return (0);
}
