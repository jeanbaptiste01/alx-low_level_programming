#include "main.h"

/**
 * print_chessboard - prints the chessboard
 * @a: input
 *
 * Return: void
 */

void print_chessboard(char (*a)[8])
{
	int y, b;

	for (y = 0; y < 8; y++)
	{
		for (b = 0 ; b < 8 ; b++)
		{
			_putchar(*((*a + y * 8) + b));
		}
		_putchar('\n');
	}
}
