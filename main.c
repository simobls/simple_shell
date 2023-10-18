#include "shell.h"

/**
 * main - Entry point for a simple shell program.
 * @ac: The argument count.
 * @argv: The argument vector.
 *
 * Return: Always 0 (success).
 */
int main(int ac, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0, idx = 0;
	(void)ac;

	while (1)
	{
		line = read_the_line();
		if (line == NULL)
		{
			/* Reached EOF (Ctrl + D) */
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return (status);
		}
		idx++;

		command = tokenizer(line);
		if (!command)
		{
			continue;
		}
		if (is_builtin(command[0]))
			handle_builtin(command, argv, &status, idx);
		else
			status = execute_(command, argv, idx);
	}
}
