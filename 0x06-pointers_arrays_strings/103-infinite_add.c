#include "main.h"

/**
 * infinite_add - Adds two numbers.
 * @n1: The first number as a string.
 * @n2: The second number as a string.
 * @r: The buffer to store the result.
 * @size_r: The size of the result buffer.
 *
 * Return: A pointer to the result buffer, or 0 if the result cannot be stored.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0, carry = 0;
	int i, j, k;

	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;
	if (size_r <= len1 || size_r <= len2)
		return (0);
	i = len1 - 1;
	j = len2 - 1;
	k = size_r - 2;
	r[k + 1] = '\0';
	while (i >= 0 || j >= 0)
	{
		int sum = carry;

		if (i >= 0)
			sum += n1[i] - '0';
		if (j >= 0)
			sum += n2[j] - '0';

		r[k] = (sum % 10) + '0';
		carry = sum / 10;

		i--;
		j--;
		k--;
	}
	if (carry)
	{
		if (k >= 0)
			r[k] = carry + '0';
		else
			return (0);
	}
	return (r + k + 1);
}

