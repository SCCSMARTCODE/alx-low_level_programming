#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 62

/**
 * main - Generates a random valid password
 *
 * Return: Always 0.
 */
int main(void)
{
    char password[PASSWORD_LENGTH + 1];
    const char valid_chars[PASSWORD_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int i, rand_index;

    srand(time(0));

    for (i = 0; i < PASSWORD_LENGTH; i++)
    {
        rand_index = rand() % PASSWORD_LENGTH;
        password[i] = valid_chars[rand_index];
    }
    password[PASSWORD_LENGTH] = '\0';

    printf("%s\n", password);

    return (0);
}

