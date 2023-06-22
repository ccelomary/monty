#include "monty.h"

/**
 * pop_stack - function that pops element from stack
 *
 * @st: stack
 * Return: popped item
 */
stack_t *pop_stack(stack_t **st)
{
	stack_t *popped;

	if (!st || !*st)
		return (NULL);
	popped = *st;
	*st = popped->next;
	if (*st)
		(*st)->prev = NULL;
	return (popped);
}
