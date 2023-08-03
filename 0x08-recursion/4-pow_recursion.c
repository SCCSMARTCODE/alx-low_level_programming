#include "main.h"

/**
 * _pow_recursion - x raised to the power of y
 *
 * @x: parameter1
 * @y: parameter2
 * Return: If y is lower than 0, the function should return -1
 */

int _pow_recursion(int x, int y)
{
	int m;


	if (y == 0)
	{
		return (1);
	}
	else if (y < 0)
	{
		return (-1);
	}

	m = x * _pow_recursion(x, y - 1);

	return (m);
}
