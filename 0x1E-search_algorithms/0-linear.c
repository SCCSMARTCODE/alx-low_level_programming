#include "search_algos.h"

/**
 * linear_search - This is a function that performs a silmple linear search
 *
 * @array: array is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 *
 * Return: If not present or if array is NULL, your function must return -1
 */

int linear_search(int *array, size_t size, int value)
{
	size_t x;

	if (!array)
	{
		return (-1);
	}

	for (x = 0; x < size; x++)
	{
		printf("Value checked array[%ld] = [%d]\n", x, array[x]);

		if (value == array[x])
		{
			return (x);
		}
	}

	return (-1);
}
