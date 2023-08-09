#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: A pointer to an array of strings (words), or NULL on failure
 */
char **strtow(char *str)
{

    int num_words;
    int i, j, word_length;
    int word_index;
    int word_start;
    char **words;

        if (str == NULL || *str == '\0')
        return (NULL);

    num_words = 0;


    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
        {
            num_words++;
        }
    }

    if (num_words == 0)
        return (NULL);

   words = (char **)malloc((num_words + 1) * sizeof(char *));
    if (words == NULL)
        return (NULL);

    word_index = 0;
    word_start = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            word_start = i;

            while (str[i] != ' ' && str[i] != '\0')
            {
                i++;
            }

            word_length = i - word_start;

            words[word_index] = (char *)malloc((word_length + 1) * sizeof(char));
            if (words[word_index] == NULL)
            {
                for (j = 0; j < word_index; j++)
                {
                    free(words[j]);
                }
                free(words);
                return (NULL);
            }

            for (j = 0; j < word_length; j++)
            {
                words[word_index][j] = str[word_start + j];
            }
            words[word_index][word_length] = '\0';

            word_index++;
        }
    }

    words[num_words] = NULL;
    return (words);
}
