#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: 0 (SUCCESS)
 */

int main(void)
{
	int n = 50;
	long int fib[50];
	int i;

	fib[0] = 1;
	fib[1] = 2;

	for (i = 2; i < n; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	for (i = 0; i < n - 1; i++)
	{
		printf("%ld, ", fib[i]);
	}

	printf("%ld\n", fib[n - 1]);

	return (0);
}
