#include "main.h"
/**
 * factorial - returns the factorial of a given number.
 *
 * @n: the parameter
 *
 * Return: If n is lower than 0, the function should return -1
 */

int factorial(int n)
{
	int m;

	if (n == 0)
	{
	return (1);
	}
	else if (n < 0)
	{
	return (-1);
	}

	m = n * factorial(n - 1);

	return (m);
}
