#include "main.h"

/**
 * _memset - function that fills memory with a constant byte
 * @b: constant char byte
 * @n: number of bytes to fill
 * @s: pointers to allocated memory
 *
 * Return: pointer to memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		s[i] = b;
		i++;
	}
	return (s);
}
