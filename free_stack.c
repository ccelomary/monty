#include "monty.h"

/**
 * free_stack - function that frees the stack
 *
 * @stack: stack to be freed
 * Return: (void)
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp, *current;

	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
