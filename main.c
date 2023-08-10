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

	process_file(monty_file);

	fclose(monty_file);

	return (EXIT_SUCCESS);
}
