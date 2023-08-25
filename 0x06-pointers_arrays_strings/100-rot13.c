#include <stdio.h>

/**
 * rot13 - Encodes a string using the ROT13 cipher.
 * @s: The input string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *rot13(char *s)
{
	char *ptr = s;
	char c;
	int i;

	while ((c = *ptr))
	{
		for (i = 0; i < 2; i++)
		{
			int diff = (i == 0) ? 13 : -13;

			if ((c >= 'a' && c <= 'z' && c + diff > 'z') ||
			    (c >= 'A' && c <= 'Z' && c + diff > 'Z'))
			{
				c -= 26;
			}

			*ptr = c + diff;
		}
		ptr++;
	}
	return (s);
}

