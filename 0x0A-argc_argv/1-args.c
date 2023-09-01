#include <stdio.h>
/**
 * main - program prints the number of arguments
 * @argc: number of command line argument
 * @argv: array containing the program's command line arguments
 * Return: 0 - success.
 */
int main(int argc, __attribute__ ((unused)) char *argv[])
{
	printf("%d\n", argc - 1);
	return (0);
}
