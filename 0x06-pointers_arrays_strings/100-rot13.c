#include "main.h"

/**
 * rot13 - Encodes a string using rot13.
 * @s: The input string.
 *
 * Return: The encoded string.
 */
char *rot13(char *s)
{
	char *ptr = s;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int index;

	while (*ptr)
	{
		index = 0;
		while (alphabet[index])
		{
			if (*ptr == alphabet[index])
			{
				*ptr = rot13[index];
				break;
			}
			index++;
		}
		ptr++;
	}

	return (s);
}

