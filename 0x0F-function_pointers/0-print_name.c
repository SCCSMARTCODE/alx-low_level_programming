#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - prints a name using a provided function
 * @name: name of the person
 * @f: function pointer to the printing function
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
