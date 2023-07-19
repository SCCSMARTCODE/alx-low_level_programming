#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: 0 (SUCCESS)
 */
int main(void)
{
	int max_no = 1024;
	int f_no = 3;
	int s_no = 5;
	int fl_no, sl_no;
	int sum1, sum2, sumt;
	float n1, n2;
	int pnn;
	int lcm_no, lcm_count, sum_lcm;

	for (pnn = 3; pnn <= 1024; pnn++)
	{
	}

	fl_no = max_no - (max_no % f_no);
	n1 = fl_no / f_no;
	sum1 = (n1 / 2) * (f_no + fl_no);


	sl_no = max_no - (max_no % s_no);
	n2 = sl_no / s_no;
	sum2 = (n2 / 2) * (s_no + sl_no);

	lcm_no = 15;
	lcm_count = max_no / lcm_no;
	sum_lcm = (lcm_count / 2) * (lcm_no + lcm_no * lcm_count);

	sumt = sum1 + sum2 - sum_lcm;
	printf("%d\n", sumt);


	return (0);
}
