#include <stdio.h>
#include "main.h"

/**
 * rot13 - applies ROT13 substitution cipher to a string.
 * @val: input string
 *
 * Return: Pointer to the resulting string
 */

char *rot13(char *val)
{
int i;

i = 0;

while (val[i] != '\0')

{
if (((val[i] >= 97) && (val[i] <= 109)) || ((val[i] >= 65) && (val[i] <= 77)))
{
val[i] = val[i] + 13;
}
else if ((val[i] >= 110 && val[i] <= 122) || (val[i] >= 78 && val[i] <= 90))
{
val[i] = val[i] - 13;
}

i++;
}

return (val);
}

