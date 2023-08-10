#include "main.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
	{
	fprintf(stderr, "malloc failed\n");
	exit(98);
	}

	return ptr;

}
