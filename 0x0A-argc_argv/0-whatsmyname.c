#include <stdio.h>

/**
 * main - Write a program that prints its name, followed by a new line.
 *
 * @argc: count parameter
 * @argv: vector parameter
 * 
 * Return: 0
 */

int main(int argc, char *argv[])
{
	printf("%s\n", argv[0]);
	(void)argc;
	return (0);
}
