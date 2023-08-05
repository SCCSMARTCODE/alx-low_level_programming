#include <stdio.h>

/**
 * main - prints the number of arguments passed into it.
 *
 * @args: a1
 * @argv: a2
 *
 * Return: 0
 */

int main(int args, char *argv[])
{
	printf("%d\n", args - 1);
	(void)argv;
	return (0);
}
