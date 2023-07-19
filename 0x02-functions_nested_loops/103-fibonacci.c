#include <stdio.h>

/**
 * main -  prints the Fibonacci numbers
 *
 * Return: 0 (SUCCESS)
 */
int main(void)
{
	unsigned long first_no = 1;
	unsigned long sec_no = 2;
	unsigned long counting_no;
	unsigned long sum = 2;


	while (1)
	{
		counting_no = first_no + sec_no;

		if (counting_no > 4000000)
		{
			break;
		}

		if (counting_no % 2 == 0)
		{
			sum += counting_no;
		}

		first_no = sec_no;
		sec_no = counting_no;

	}

	printf("%lu\n", sum);

	return (0);
}
