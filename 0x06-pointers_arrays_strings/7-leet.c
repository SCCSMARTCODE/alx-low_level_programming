#include "main.h"
#include <stdio.h>

/**
 * leet - encodes a string into 1337 (leet speak).
 * @str: input string
 *
 * Return: Pointer to the resulting string
 */

char *leet(char *str)
{
	int i;
	char *ptr;
	char *leet_chars = "aAeEoOtTlL";
	char *leet_nums = "4433007711";

	ptr = str;
	while (*ptr)
	{
	for (i = 0; leet_chars[i]; i++)
	{
	if (*ptr == leet_chars[i])	
	{
	*ptr = leet_nums[i];
	break;
	}
        }

		ptr++;
	}
	return (str);
}
