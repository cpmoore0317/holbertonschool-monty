#include "monty.h"

/**
 * exec_opcode - Calls the correct opcode function
 * @opcode: Function to find
 *
 * Return: Correct function
 */

void (*exec_opcode(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t function_select[] = {
		{"push", push_opcode},
		{"pall", pall_opcode},
		{"pint", pint_opcode},
		/*{"pop", pop_opcode},
		{"swap", swap_opcode},
		{"add", add_opcode},
		{"nop", nop_opcode},*/
	};

	int i;

	for (i = 0; function_select[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, function_select[i].opcode) == 0)
		{
			return (function_select[i].f);
		}
	}
	return (NULL);
}
