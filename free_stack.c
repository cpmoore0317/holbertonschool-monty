#include "monty.h"

/**
 * free_stack - Frees all of the stack
 * @stack: Pointer to stack
 *
 * Return: Void
 */

void free_stack(stack_t **stack)
{
	stack_t *current_node = stack;
	stack_t *next_node;

	while (current_node)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
}
