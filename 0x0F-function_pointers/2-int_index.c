#include <stdio.h>
#include "function_pointers.h"
/**
 * int_index - take back  index place if comparison = true,otherwise -1
 * @array: array
 * @size: size of elements in arr
 * @cmp: pointer to funcion of one of the 3 in main
 * Return: 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int c;

	if (array == NULL || size <= 0 || cmp == NULL)
	return (-1);
	for (c = 0; c < size; c++)
	{
	if (cmp(array[c]))
	return (c);
	}
	return (-1);
}
