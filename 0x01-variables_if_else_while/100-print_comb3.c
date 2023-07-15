#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	int Good;
	int zero;

	zero = 0;

	for (Good = 1; Good <= 89; Good++)
	{
		if (Good < 10)
		{
			putchar(zero + '0');
		}
		if (Good == 10 || Good == 11 || Good == 20 || Good == 21 || Good == 22)
		{
			continue;
		}
		if ((Good > 29 && Good < 34) || (Good > 39 && Good < 45))
		{
			continue;
		}
		if ((Good > 59 && Good < 67) || (Good > 49 && Good < 56))
		{
			continue;
		}
		if ((Good > 69 && Good < 78) || (Good > 79 && Good < 89))
		{
			continue;
		}

		putchar(Good + '0');
		if (Good != 89)
		{
			putchar(',');
			putchar(' ');
		}
	}

	return (0);
}
