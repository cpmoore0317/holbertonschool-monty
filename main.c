#include "monty.h"

/**
 * main - Checks if the file is valid, opens file, gets input, checks for
 * opcodes, executes opcodes, cleans up data and closes file.
 * @argc: Number of arguments
 * @argv: Vector of arguments
 *
 * Return: EXIT_SUCCESS
 */

int main(int argc, char **argv)
{
	unsigned int line_number = 0;
	char *line_buffer = NULL;
	char *opcode_string = NULL;
	size_t line_buffer_size = 0;
	stack_t *top = NULL;
	void (*function_pointer)(stack_t **, unsigned int);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *monty_file = fopen(argv[1], "r");

	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line_buffer, &line_buffer_size, monty_file) != -1)
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
	fclose(monty_file);
	free_stack(top);

	return (EXIT_SUCCESS);
}
