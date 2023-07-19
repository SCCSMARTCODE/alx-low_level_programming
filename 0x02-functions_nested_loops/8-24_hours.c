#include "main.h"
#include <stdio.h>

/**
 * jack_bauer - starter
 *
 * Return: last woek
 */

void jack_bauer(void)
{
	int a, b;

	for (a = 0; a <= 23; a++)
	{

		for (b = 0; b <= 59; b++)
		{
			if (a < 10)
		{
			printf("0");
		}

			printf("%d", a);

		printf(":");

		if (b < 10)
		{
			printf("0");
		}

			printf("%d\n", b);
		}
	}
}
