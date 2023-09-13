#include <stdio.h>
#include "function_pointers.h"
/**
 * array_iterator - outputs each array element on a newl
 * @array: array
 * @size: the number o elements to output
 * @action: pointer to output in regular or hex
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int k;

	if (array == NULL || action == NULL)
	return;
	for (k = 0; k < size; k++)
	{
	action(array[k]);
	}
}
