#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Pointer to the unsigned long int number where the bit is to be cleared.
 * @index: The index of the bit to be cleared, starting from 0.
 *
 * Return: 1 if successful, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	mask = 1UL << index; /* Create a mask with the desired bit set */
	mask = ~mask; /* Invert the mask to clear the desired bit */

	*n &= mask; /* Use bitwise AND to clear the bit */

	return (1); /* Successful operation */
}

