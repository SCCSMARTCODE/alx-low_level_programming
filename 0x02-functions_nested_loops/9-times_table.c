#include <stdio.h>
#include "main.h"

/**
 * times_table - that print the 9 times table, starting with 0
 *
 * Return: Void
 */

void times_table(void)
{
	int i;
	int r;

	for (i = 0; i <= 9; i++)
	{
		for (r = 0; r <= 9; r++)
		{
			int ans = i * r;

			if (r != 0)
			{
				if (ans >= 10)
				{
					printf(", ");
				}
				else
				{
					printf(",  ");
				}
			}

			printf("%d", ans);

		}

		printf("\n");
	}
}
