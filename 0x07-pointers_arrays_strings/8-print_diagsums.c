#include "main.h"

/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix
 * @a: a
 * @size: size
 *
 * Return: void
 */

void print_diagsums(int *a, int size)
{
	int y;
	int sum0 = 0;
	int sum1 = 0;

	for (y = 0; y < (size * size); y++)
	{
		if (y % (size + 1) == 0)
			sum0 += *(a + y);
		if (y % (size - 1) == 0 && y != 0 && y < size * size - 1)
			sum1 += *(a + y);
	}
	printf("%d, %d\n", sum0, sum1);
}
