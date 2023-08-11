#include "monty.h"

/**
 * pall_opcode - Print all nodes of the current stack
 * @stack: Pointer to the stack
 * @n: Current line number (unused)
 *
 * Return: Void
 */

void pall_opcode(stack_t **stack, unsigned int __attribute__((unused)) ln)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
