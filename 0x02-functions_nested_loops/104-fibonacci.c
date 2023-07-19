#include <stdio.h>

/**
 * main -  prints the first 98 Fibonacci numbers
 *
 * Return: 0 (SUCCESS)
 */
int main(void)
{
	unsigned long long first_no;
	unsigned long long sec_no;
	unsigned long long counting_no;
	int i;

	first_no = 1;
	sec_no = 2;

	printf("%llu, %llu, ", first_no, sec_no);

	for (i = 2; i < 98; i++)
	{
		counting_no = first_no + sec_no;

		first_no = sec_no;
		sec_no = counting_no;

		printf("%llu", counting_no);

		if (i != 97)
		{
			printf(", ");
		}

	}
	printf("\n");
	return (0);
}
