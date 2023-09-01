#include <stdio.h>
/**
 * main - program prints all arguments, including the first one
 * @argc: gives the number of arguments
 * @argv: array of arguments passed
 * Return: 0 - success.
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
