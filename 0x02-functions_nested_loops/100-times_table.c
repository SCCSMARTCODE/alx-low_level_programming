#include <stdio.h>
#include "main.h"

/**
 * print_times_table - prints the n times table, starting with 0
 *
 * @n: determinant
 *
 * Return: void
 */

void print_times_table(int n)
{
	int x, y;
	int ans;

	if (n <= 15 && n >= 0)
		{
		for (x = 0; x <= n; x++)
		{
			for (y = 0; y <= n; y++)
			{
				ans = x * y;

				if (n <= 15 && n >= 0)
				{
					if (y != 0)
					{
					if (ans <= 9)
						{
						printf(",   ");
						}
					else if (ans > 99)
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
			}

			printf("\n");
		}

	}


}
