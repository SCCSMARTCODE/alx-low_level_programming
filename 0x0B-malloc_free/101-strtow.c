#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int count_words(char *str);
char **allocate_words(char *str, int word_count);
void copy_characters(char **words, char *str);

/**
 * strtow - Splits a string into words.
 * @str: The input string
 *
 * Return: A pointer to an array of strings (words),
 *         or NULL if str == NULL or str == "" or if the function fails.
 */

char **strtow(char *str)
{
	char **words;
	int word_count;

	if (str == NULL || str[0] == '\0')
	return (NULL);

	word_count = count_words(str);
	if (word_count == 0)
	return (NULL);

	words = allocate_words(str, word_count);
	if (words == NULL)
	return (NULL);

	copy_characters(words, str);

	return (words);
}

/**
 * count_words - Counts the number of words in a string.
 * @str: The input string
 *
 * Return: The number of words in the string.
 */

int count_words(char *str)
{
	int word_count = 0;
	int in_word = 0;
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
	if (str[i] != ' ' && !in_word)
	{
	in_word = 1;
	word_count++;
	}
	else if (str[i] == ' ')
	{
	in_word = 0;
	}
	}

	return (word_count);
}

/**
 * allocate_words - Allocates memory for an array of words.
 * @str: The input string
 * @word_count: The number of words
 *
 * Return: A pointer to the allocated array of words, or NULL if allocation
 */

char **allocate_words(char *str, int word_count)
{
	int i;
	int word_length, j;

	char **words = (char **)malloc((word_count + 1) * sizeof(char *));

	if (words == NULL)
	return (NULL);

	i = 0;
	while (*str != '\0')
	{
	while (*str == ' ')
	str++;

	word_length = 0;
	while (str[word_length] != ' ' && str[word_length] != '\0')
	word_length++;

	words[i] = (char *)malloc((word_length + 1) * sizeof(char));
	if (words[i] == NULL)
	{
	for (j = 0; j < i; j++)
	free(words[j]);
	free(words);
	return (NULL);
	}

	i++;
	str += word_length;
	}

	words[i] = NULL;
	return (words);
}

/**
 * copy_characters - Copies characters from a string to an array of words.
 * @words: The array of words
 * @str: The input string
 */

void copy_characters(char **words, char *str)
{
	int i = 0, word_length, j;

	while (*str != '\0')
	{
	while (*str == ' ')
	str++;

	word_length = 0;
	while (str[word_length] != ' ' && str[word_length] != '\0')
	word_length++;

	for (j = 0; j < word_length; j++)
	words[i][j] = str[j];

	words[i][word_length] = '\0';
	i++;
	str += word_length;
	}
}
