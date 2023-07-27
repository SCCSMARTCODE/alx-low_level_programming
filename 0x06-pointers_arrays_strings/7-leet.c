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
	char *ptr;
	char leet_arr[256] = {0};
	char *leet_chars = "aAeEoOtTlL";
	char *leet_nums = "4433007711";

	while (*leet_chars)
	{
	leet_arr[(unsigned char)(*leet_chars)] = *leet_nums;
	leet_chars++;
	leet_nums++;
	}

	ptr = str;
	while (*ptr)
	{
		if (*ptr >= 'A' && *ptr <= 'Z')
			*ptr = leet_arr[(unsigned char)(*ptr)];
		else if (*ptr >= 'a' && *ptr <= 'z')
			*ptr = leet_arr[(unsigned char)(*ptr)];
		ptr++;
	}
	return (str);
}
