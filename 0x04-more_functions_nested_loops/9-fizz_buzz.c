#include <stdio.h>

/**
 * main - The “Fizz-Buzz test”
 *
 * Return: Always 0
 */

int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{

	if (i % 15 == 0)
	{
	printf("FizzBuzz ");
	continue;
	}
	else if (i % 3 == 0)
	{
	printf("Fizz ");
	continue;
	}
	else if (i % 5 == 0 && i != 100)
	{
	printf("Buzz ");
	continue;
	}
	else if (i == 100)
	{
	printf("Buzz");
	continue;
	}

	printf("%d ", i);

	}

	printf("\n");
	return (0);
}

