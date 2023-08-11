#include "monty.h"

/** pop_opcode - Removes the top element of the stack
 * @stack: Pointer to the stack
 * @ln: Current line number
 *
 * Return: Void, EXIT_FAILURE if stack is empty 
 */

void pop_opcode(stack_t **stack, unsigned int ln)
{
	stack_t *current_node = *stack;

	if (current_node == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}

	*stack = current_node->next;

	if (current_node->next != NULL)
		current_node->next->prev = NULL;
	free(current_node);
}
