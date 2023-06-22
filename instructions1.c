#include "monty.h"

/**
 * push - function that pushs the number to the stack
 *
 * @stack: stack
 * @line_number: the current line number
 * @s: string
 * Return: (void)
 */
void push(stack_t **stack, unsigned int line_number,
		  __attribute__((__unused__)) const char *s)
{
	if (!_isdigit(s))
	{
		fprintf(stderr, "L<%u>: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	push_stack(stack, atoi(s));
}

/**
 * pall - function that print all the elements inside
 * of the stacks
 *
 * @stack: stack
 * @line_number: the current line number
 * @s: string
 * Return: (void)
 */
void pall(stack_t **stack, unsigned int line_number,
		  __attribute__((__unused__)) const char *s)
{
	(void)line_number;
	print_stack(*stack, -1);
}

/**
 * pall - function that print integer at the top of the stack
 * the elements inside of the stacks
 *
 * @stack: stack
 * @line_number: the current line number
 * @s: string
 * Return: (void)
 */
void pint(stack_t **stack, unsigned int line_number,
		  __attribute__((__unused__)) const char *s)
{
	if (!*stack)
	{
		fprintf(stderr, "L<%u>: can't pint, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	print_stack(*stack, 1);
}
/**
 * pop - function that pop element from the stack
 *
 * @stack: stack
 * @line_number: the current line number
 * @s: string
 * Return: (void)
 */
void pop(stack_t **stack, unsigned int line_number,
		 __attribute__((__unused__)) const char *s)
{
	stack_t *node;

	if (!*stack)
	{
		fprintf(stderr, "L<%u>: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	node = pop_stack(stack);
	free(node);
}

/**
 * swap - function that switch two last elements in
 * the stacks
 *
 * @stack: stack
 * @line_number: the current line number
 * @s: string
 * Return: (void)
 */
void swap(stack_t **stack, unsigned int line_number,
		  __attribute__((__unused__)) const char *s)
{
	stack_t *a, *b;

	if (stack_length(*stack) < 2)
	{
		fprintf(stderr, "L<%u>: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	a = pop_stack(stack);
	b = pop_stack(stack);
	push_stack(stack, a->n);
	push_stack(stack, b->n);
	free(a);
	free(b);
}
