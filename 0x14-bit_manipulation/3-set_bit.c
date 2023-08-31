#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: Pointer to the unsigned long int number where the bit is to be set.
 * @index: The index of the bit to be set, starting from 0.
 *
 * Return: 1 if successful, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	mask = 1UL << index; /* Create a mask with the desired bit set */

	*n |= mask; /* Use bitwise OR to set the bit */

	return (1); /* Successful operation */
}

