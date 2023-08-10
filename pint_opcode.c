#include "monty.h"

/**
 * pint_opcode - Prints the first node on the stack
 * @stack: Pointer to the stack
 * @ln: Current line number
 *
 * Return: Void, EXIT_FAILURE if the stack is empty
 */

void pint_opcode(stack_t **stack, unsigned int ln)
{
	stack_t *current_node = NULL;

	current_node = *stack;
	if (current_node == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", current_node->n);
}
