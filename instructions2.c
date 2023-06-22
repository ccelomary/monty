#include "monty.h"

/**
 * add - function that add two last numbers in the stack
 *
 * @stack: stack
 * @line_number: the current line number
 * @s: string
 * Return: (void)
 */
void add(stack_t **stack, unsigned int line_number,
		 __attribute__((__unused__)) const char *s)
{
	stack_t *a, *b;

	if (stack_length(*stack) < 2)
	{
		fprintf(stderr, "L<%u>: can't add, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	a = pop_stack(stack);
	b = pop_stack(stack);
	push_stack(stack, a->n + b->n);
	free(a);
	free(b);
}
