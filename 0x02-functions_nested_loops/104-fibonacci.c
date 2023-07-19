#include <stdio.h>

/**
 * main -  prints the first 98 Fibonacci numbers
 *
 * Return: 0 (SUCCESS)
 */
int main(void)
{
	unsigned long first_no;
	unsigned long sec_no;
	unsigned long counting_no;
	int i;

	first_no = 0;
	sec_no = 1;

	for (i = 2; i <= 98; i++)
	{
		counting_no = first_no + sec_no;

		first_no = sec_no;
		sec_no = counting_no;

		printf("%lu", counting_no);

		if (i != 98)
		{
			printf(", ");
		}

	}
	printf("\n");
	return (0);
}
