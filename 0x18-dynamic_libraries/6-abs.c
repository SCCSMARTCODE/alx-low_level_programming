#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _abs - computes the absolute value of an integer.
 *
 * @x: the integer
 *
 * Return: absolute value
 */

int _abs(int x)
{

	if (x < 0)
	{
		int y;

		y = x * -1;

		return (y);
	}

	return (x);
}
