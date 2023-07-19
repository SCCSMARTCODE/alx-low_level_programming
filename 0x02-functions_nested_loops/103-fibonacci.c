#include <stdio.h>

/**
 * main -  prints the Fibonacci numbers
 *
 * Return: 0 (SUCCESS)
 */
int main(void)
{
	unsigned long first_no = 2;
	unsigned long sec_no = 4;
	unsigned long counting_no;
	int i;

	printf("%lu, %lu, ", first_no, sec_no);

	for (i = 2; i < 98; i++)
	{
		counting_no = first_no + sec_no;

		first_no = sec_no;
		sec_no = counting_no;

		if (counting_no > 4000000)
		{
			break;
		}

		printf("%lu", counting_no);

		if (i < 29)
		{
			printf(", ");
		}

	}

	printf("\n");

	return (0);
}
