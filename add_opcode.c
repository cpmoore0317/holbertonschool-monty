#include "monty.h"

/**
 * add_opcode - Adds the top two elements of the stack
 * @stack: A pointer to the stack
 * @ln: The current line number
 *
 * Return: Void
 */

void add_opcode(stack_t **stack, unsigned int ln)
{
	stack_t *node1, *node2;

		if (*stack == NULL || (*stack)->next == NULL)
		{
			fprintf(stderr, "L%u: can't add, stack too short\n", ln);
			exit(EXIT_FAILURE);
		}
	
	/* Store the addresses of the top two elements of the stack */
	node1 = *stack;
	node2 = node1->next;

	/* Add the value of the second element to the first element */
	node2->n += node1->n;

	/* Update the stack pointer to point to the second element */
	*stack = node2;

	/* Set the previous pointer of the new top element to NULL */
	node2->prev = NULL;

	/* Free the memory occupied by the old top element */
	free(node1);
}
