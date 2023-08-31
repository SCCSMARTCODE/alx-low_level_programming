#include <stddef.h>

/**
 * binary_to_uint - Converts a binary string to an unsigned int.
 * @b: The binary string to convert.
 *
 * Return: The converted unsigned int, or 0 if invalid input.
 */
unsigned int binary_to_uint(const char *b)
{
	/* Initialize variables */
	unsigned int sum = 0;
	int i = 0;

	if (b == NULL)
	{
		return (0);
	}

	while (b[i] != '\0')
	{
		if (b[i] != '0' && b[i] != '1')
		{
			return (0);	/* Invalid character found in the binary string */
		}
		sum = sum * 2 + (b[i] - '0');	/* Convert and accumulate */
		i++;
	}

	return (sum);
}
