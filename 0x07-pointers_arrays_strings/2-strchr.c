#include "main.h"

/**
 * _strchr - function that locates a character in a string
 * @s: string to search
 * @c: char to
 *
 * Return: pointer to s else null
 */

char *_strchr(char *s, char c)
{
	int y;

	y = 0;
	while (s[y] != '\0')
	{
		if (s[y] == c)
			return ((s + y));
		y++;
	}
	if (c == '\0')
		return ((s + y));
	return (NULL);
}
