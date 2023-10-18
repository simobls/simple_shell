#include "shell.h"

/**
 * main - Entry point for a simple shell program.
 *
 * Return: Always 0 (success).
 */

int main(void)
{
	init();
	while (1)
	{
		char *input = read_input();
		char **args = parse_input(input);

		execute(args);
		free(input);
		free(args);
	}
	return (0);
}
