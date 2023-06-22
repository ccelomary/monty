#include "monty.h"

/**
 * print_stack - function that print n nodes inside
 * of the stack
 *
 * @st: stack
 * @n: number of nodes that will be printed
 * Return: (void)
 */
void print_stack(const stack_t *st, int n)
{
	int iterator;

	iterator = 0;
	while (st && (n == -1 || iterator < n))
	{
		printf("%d\n", st->n);
		st = st->next;
		iterator++;
	}
}
