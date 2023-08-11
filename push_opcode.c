#include "monty.h"

/**
 * push_opcode - Push a new node into the stack
 * @stack: Pointer to the stack
 * @line_number: Current line number in file
 *
 * Return: No return, EXIT_FAILURE if fails
 */

void push_opcode(stack_t **stack, unsigned int ln)
{
	stack_t *new_node = NULL;
	char *char_to_int = NULL;
	int num = 0;

	char_to_int = strtok(NULL, DELIM);
	if (char_to_int == NULL || !isdigit((unsigned char)*char_to_int))
	{
		fprintf(stderr, "L%u: usage: push integer\n", ln);
		exit(EXIT_FAILURE);
	}

	num = atoi(char_to_int);
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack == NULL)
	{
		*stack = new_node;
		return;
	}
	new_node->next = *stack;
	(*stack)->prev = new_node;
	*stack = new_node;
}
