#include "shell.h"

/**
 * read_the_line - Read a line of input from the user.
 *
 * Return: A pointer to the input line or NULL if an error occurs.
 */
char *read_the_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	n = getline(&line, &len, stdin);
	if (n == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
