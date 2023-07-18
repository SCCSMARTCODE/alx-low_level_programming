#include <stdio.h>
#include "main.h"

/**
 * print_to_98 -  print all natural numbers from n to 98
 *
 * @n: needed value
 *
 * Return: n value
 */

void print_to_98(int n)
{
	int i;

	if (n < 98)
	{
		for (i = n; i <= 98; i++)
		{
			printf("%d", i);

			if (i != 98)
			{
				printf(", ");
			}
		}

		printf("\n");
	}
	else if (n > 98)
	{
		for (i = n; i >= 98; i--)
		{
			printf("%d", i);
			if (i != 98)
			{
				printf(", ");
			}
		}
		printf("\n");
	}
	else
	{
		if (n == 98)
		{
			i = n;

			printf("%d\n", i);
		}

	}

	printf("\n");
}