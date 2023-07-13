#include <stdio.h>

/**
 * main = starting work;
 */
int main(void)
{
	int day;
	char name[50];
	char month[18];

	printf("your name, month of birth, day of birth:\n");
	scanf("%s %s %d", name, month, &day);

	printf("ooh %s you are a %s born \n
	your birthday is on %dth of %s\n", name, month, day, month);

	return (0);
}
