#include "main.h"
#include <stdio.h>

/**
 * _strchr - locates a character in a string.
 *
 * @s: parameter1
 * @c:parameter2
 *
 * Return: a pointer to the first occurrence of the character c in the string s
 */

char *_strchr(char *s, char c)
{
	while (*s)
	{
	if (*s == c){
	return s;}
	s++;
	}

	if (*s == c)
	{
	return (s);
	}
return (NULL);
}
