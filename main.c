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
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", _div},
		{"mod", mod},
		{"nop", NULL}};

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
	monty(file, &stack, instructions);
	fclose(file);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
