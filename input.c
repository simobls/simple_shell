#include "shell.h"

/**
 * read_input - Reads user input from the standard input and returns it as a
 * string. Uses the getline function to read input of any length.
 *
 * Return: String.
 */
char *read_input(void)
{
	char *input = NULL;
	size_t size = 0;

	getline(&input, &size, stdin);
	input[strcspn(input, "\n")] = '\0';
	return (input);
}

/**
 * parse_input - Parses the user input into an array of strings, where each
 * string represents an argument. Uses the strtok function to split the input
 * string into tokens based on whitespace.
 *
 * @input: String to be parsed.
 *
 * Return: Array of strings.
 */
char **parse_input(char *input)
{
	char **args = malloc(64 * sizeof(char *));
	char *token = strtok(input, " ");
	int i = 0;

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	return (args);
}
