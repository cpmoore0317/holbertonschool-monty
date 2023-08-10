#include "monty.h"

void process_file(FILE *file)
{
	unsigned int line_number = 0;
	char *line_buffer = NULL;
	char *opcode_string = NULL;
	size_t line_buffer_size = 0;
	stack_t *top = NULL;
	void (*function_pointer)(stack_t **, unsigned int);

	while (getline(&line_buffer, &line_buffer_size, file) != -1)
	{
		line_number++;
		opcode_string = strtok(line_buffer, DELIM);

		if (opcode_string == NULL || strcmp(opcode_string, "\n") == 0)
			continue;

		function_pointer = exec_opcode_func(opcode_string);

		if (function_pointer == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode_string);
			exit(EXIT_FAILURE);
		}

		function_pointer(&top, line_number);
	}

	free(line_buffer);
	free_stack(top);
}
