#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: 0 (SUCCESS)
 */

int main() {
	int n = 50;
	long long int fib[50];
    
	fib[0] = 1;
	fib[1] = 2;
    
	for (int i = 2; i < n; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}

	for (int i = 0; i < n-1; i++) {
		printf("%lld, ", fib[i]);
	}

	printf("%lld\n", fib[n-1]);

	return 0;
}
