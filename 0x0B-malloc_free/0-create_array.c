#include "main.h"
#include <stdlib.h>

/**
 * create_array -  creates an array of chars
 *
 * @size: para1
 * @c: para2
 *
 * Return: ptr
 */

char *create_array(unsigned int size, char c)
{
	char *ptr;
	unsigned int i;


	ptr = malloc(size * sizeof(char));

	if ((ptr == NULL) || (size == 0))
		return (NULL);

	else
	{
		for (i = 0; i < size; i++)
			ptr[i] = c;
		return (ptr);
	}

}
