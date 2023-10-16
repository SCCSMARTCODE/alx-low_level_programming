#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * _strcat - The external coping function
 *
 * @dest: first parameter
 *
 * @src: second parameter
 *
 * Return: a pointer
 */

char *_strcat(char *dest, char *src)
{
	strcat(dest, src);

	return (dest);
}
