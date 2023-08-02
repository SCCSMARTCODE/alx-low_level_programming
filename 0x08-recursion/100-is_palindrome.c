#include "main.h"

int is_palindrome_helper(char *s, int start, int end);

int _strlen(char *s);

/**
 * _strlen - returns the length of a string
 * @s: the input string
 * Return: length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
	len++;
	s++;
	}
	return len;
}

/**
 * is_palindrome_helper - helper function to check if a string is a palindrome recursively
 * @s: the input string
 * @start: start index of the string
 * @end: end index of the string
 * Return: 1 if the string is a palindrome, otherwise 0
 */
int is_palindrome_helper(char *s, int start, int end)
{
	if (start >= end)
	{
	return 1;
	}

	if (s[start] != s[end])
	{
	return 0;
	}

	return is_palindrome_helper(s, start + 1, end - 1);
}

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: the input string
 * Return: 1 if the string is a palindrome, otherwise 0
 */
int is_palindrome(char *s)
{
	int len = _strlen(s);

	return is_palindrome_helper(s, 0, len - 1);
}

