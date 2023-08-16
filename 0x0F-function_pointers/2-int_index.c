#include "function_pointers.h"
#include <stddef.h>

/**
 * int_index - searches for an integer in an array.
 * @array: the array to search in.
 * @size: the number of elements in the array.
 * @cmp: pointer to the comparison function.
 *
 * Return: index of the first element for which cmp doesn't
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array != NULL && cmp != NULL)
	{
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
		return (i);
	}
	}
	return (-1);
}
