#include "monty.h"

/**
 * main - entry point of the program
 *
 * @ac: number of provided arguments
 * @av: arguments in 2d array format
 * Return: EXIT_SUCCESS OR EXIT_FAILURE
 */
int main(int ac, char **av)
{
	FILE *file;
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}
	monty(file, &stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
