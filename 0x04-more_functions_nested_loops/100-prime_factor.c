#include <stdio.h>

/**
 * main - Finds and prints the largest prime factor of a given number.
 *
 * Return: Always 0.
 */

int main(void)
{
long number = 612852475143;
long factor = 2;
long largest_prime_factor = 0;

while (number > 1)
{
if (number % factor == 0)
{
largest_prime_factor = factor;
while (number % factor == 0)
{
number /= factor;
}
}
factor++;
}

printf("%ld\n", largest_prime_factor);

return (0);
}

