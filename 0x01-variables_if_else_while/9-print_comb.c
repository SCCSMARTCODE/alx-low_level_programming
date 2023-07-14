#include <stdio.h>

/**
 * main Entry point
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	int man;

	for (man = 0; man <= 9; man++)
	{
		putchar(man + '0');
		if (man != 9)
		{
			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');

	return (0);

}
