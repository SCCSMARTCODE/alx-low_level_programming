#include "search_algos.h"

/**
 * binary_search - Perform binary search on a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the found value, or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{

	size_t big = 0, end = size - 1, mid = (end + big) / 2, x;

	if (!array)
		return (-1);

	do {
		x = big;

		printf("Searching in array:");
		while (x <= end)
		{
			printf(" %d", array[x]);
			if (x != end)
				printf(",");
			x++;
		}
		printf("\n");

		if (value > array[mid])
			big = mid + 1;
		else if (value < array[mid])
			end = mid - 1;
		else
			return (mid);

		mid = (end + big) / 2;
	} while (big <= end);

	return (-1); /* Value not found */
}
