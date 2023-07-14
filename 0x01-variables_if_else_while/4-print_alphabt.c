#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	char alpha_bet;

	for (alpha_bet = 'a'; alpha_bet <= 'z'; alpha_bet++)
	{
		if (alpha_bet == 'q' || alpha_bet == 'e')
		{
			continue;
		}
		putchar(alpha_bet);
	}

	putchar('\n');

	return (0);
}
