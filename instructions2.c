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

/**
 * sub - subtracts the top element of the stack from the second top element
 *			of the stack.
 * @stack: stack
 * @line_number: the current line number
 * @s: string
 * Return: (void)
 */
void sub(stack_t **stack, unsigned int line_number,
		 __attribute__((__unused__)) const char *s)
{
	stack_t *a, *b;

	if (stack_length(*stack) < 2)
	{
		fprintf(stderr, "L<%u>: can't sub, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	a = pop_stack(stack);
	b = pop_stack(stack);
	push_stack(stack, a->n + b->n);
	free(a);
	free(b);
}

/**
 * div - function that divides the second top element of the stack by the top
 *			element of the stack.
 *
 * @stack: stack
 * @line_number: the current line number
 * @s: string
 * Return: (void)
 */
void div(stack_t **stack, unsigned int line_number,
		 __attribute__((__unused__)) const char *s)
{
	stack_t *a, *b;

	if (stack_length(*stack) < 2)
	{
		fprintf(stderr, "L<%u>: can't div, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	a = pop_stack(stack);
	b = pop_stack(stack);
	if (b->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        free(a);
        free(b);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }
	push_stack(stack, b->n / a->n);
	free(a);
	free(b);
}

/**
 * mul - multiplies the second top element of the stack with the top
 *			element of the stack.
 * @stack: stack
 * @line_number: the current line number
 * @s: string
 * Return: (void)
 */
void mul(stack_t **stack, unsigned int line_number,
         __attribute__((__unused__)) const char *s)
{
    stack_t *a, *b;

    if (stack_length(*stack) < 2)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }
    a = pop_stack(stack);
    b = pop_stack(stack);
    push_stack(stack, a->n * b->n);
    free(a);
    free(b);
}

/**
 * mod - computes the rest of the division of the second top element of the stack
 *
 * @stack: stack
 * @line_number: the current line number
 * @s: string
 * Return: (void)
 */
void mod(stack_t **stack, unsigned int line_number,
         __attribute__((__unused__)) const char *s)
{
    stack_t *a, *b;

    if (stack_length(*stack) < 2)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }
    a = pop_stack(stack);
    b = pop_stack(stack);
    if (a->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        free(a);
        free(b);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }
    push_stack(stack, b->n % a->n);
    free(a);
    free(b);
}
