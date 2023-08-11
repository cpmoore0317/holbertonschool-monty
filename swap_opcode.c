#include "monty.h"

/**
 * swap_opcode - Swaps the top two elements of the stack
 * @stack: Pointer to the stack
 * @ln: Current line number
 *
 * Return: Void, EXIT_FAILURE if swap is not possible
 */

void swap_opcode(stack_t **stack, unsigned int ln)
{
	int aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = aux;
}
