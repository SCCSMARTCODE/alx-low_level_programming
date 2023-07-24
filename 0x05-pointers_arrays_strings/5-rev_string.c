#include "main.h"
#include <stddef.h>

/**
 * rev_string - function that reverses a string
 *
 * @s: Pointer to the string to be reversed
 *
 * Return: void
 */
void rev_string(char *s)
{
	int length = 0;
	int start, end;
	char temp;

	if (s != NULL)
	{
	while (s[length] != '\0')
	{
	length++;
	}

	start = 0;
	end = length - 1;

	while (start < end)
	{
	temp = s[start];
	s[start] = s[end];
	s[end] = temp;

	start++;
	end--;
	}
	}
}

