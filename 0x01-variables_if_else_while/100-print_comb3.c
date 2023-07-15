#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	int firstDigit;

	for (firstDigit = 0; firstDigit <= 8; firstDigit++)
	{
		int secondDigit;

		for (secondDigit = firstDigit + 1; secondDigit <= 9; secondDigit++)
		{
			putchar(firstDigit + '0');
			putchar(secondDigit + '0');

			if (!(firstDigit == 8 && secondDigit == 9))
			{
				putchar(',');
				putchar(' ');
			}
		}
	}

	putchar('\n');

	return (0);
}

