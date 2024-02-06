#include "search_algos.h"
#include <math.h>

int jump_search(int *array, size_t size, int value)
{
	size_t key = sqrt(size), x = 0, y;

	if (!array)
		return (-1);

	while (x < size)
	{
		if (value > array[x])
		{
			printf("Value checked array[%ld] = [%d]\n", x, array[x]);

			if (value > array[x + key])
			{
				x += key;
				continue;
			}
			else
			{
				printf("Value found between indexes [%ld] and [%ld]\n", x, x + key);

				for (y = x; y <= (x + key); y++)
				{
					if (value == array[y])
					{
						printf("Value checked array[%ld] = [%d]\n", y, array[y]);
						return (y);
					}
					printf("Value checked array[%ld] = [%d]\n", y, array[y]);
				}
			}
		}
	}

	return (-1);
}
