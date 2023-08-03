#include "main.h"

int sqrt_helper(int n, int i);

/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: The number to calculate the square root of.
 *
 * Return: The natural square root of 'n', or -1 if there is nosquare root.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	return (-1);

	return (sqrt_helper(n, 1));
}

/**
 * sqrt_helper - helper function for calculating the square root recursively.
 * @n: The number to calculate the square root of.
 * @i: The current integer to check as a possible square root.
 *
 * Return: The square root of 'n', or -1 if there is no natural square root.
 */
int sqrt_helper(int n, int i)
{
	if (i * i == n)
	return (i);
	else if (i * i > n)
	return (-1);

	return (sqrt_helper(n, i + 1));
}

