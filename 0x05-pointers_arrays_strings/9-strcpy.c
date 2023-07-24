#include "main.h"

/**
 * _strcpy - Copies the string pointed to by src to dest
 *
 * @dest: Pointer to the destination buffer
 * @src: Pointer to the source string
 *
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *dest_start = dest;

	while (*src)
	{
	*dest = *src;
	dest++;
	src++;
	}

	*dest = '\0';
	return (dest_start);
}
