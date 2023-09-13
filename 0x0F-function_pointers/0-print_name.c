#include <stdio.h>
#include "function_pointers.h"
/**
 * print_name - output name  to function using pointer
 * @name: string to includd
 * @f: pointer to function
 * Return: nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
	return;
	f(name);
}
