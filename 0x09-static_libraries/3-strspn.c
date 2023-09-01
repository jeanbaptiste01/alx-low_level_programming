#include "main.h"

/**
 * _strspn - function that gets the length of a prefix substring
 * @s: string to search
 * @accept: bytes in which to search for
 *
 * Return: n bytes
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, z, count, checker;

	i = 0;
	z = 0;
	checker = 0;
	count = 0;
	while (s[i] != '\0')
	{
		z = 0;
		checker = 0;
		while (accept[z] != '\0')
		{
			if (accept[z] == s[i])
			{
				count++;
				checker = 1;
				/* Break to early increase efficiency */
				break;
			}
			z++;
		}
		if (checker == 0)
			return (count);
		i++;
	}
	return (count);

}
