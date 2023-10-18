#include "shell.h"

/**
 * tokenizer - Tokenize a string into an array of strings.
 * @line: The input string to tokenize.
 * Return: An array of strings containing the tokens, or NULL on failure.
 */
char **tokenizer(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int cpt = 0, i = 0;

	if (!line)
		return (NULL);

	tmp = _strdup(line);
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(tmp), tmp = NULL;
		free(line), line = NULL;
		return (NULL);
	}
	cpt = 0;
	while (token)
	{
		cpt++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;

	command = malloc(sizeof(char *) * (cpt + 1));
	if (!command)
	{
		free(line), line = NULL;
		return (NULL);
	}

	token = strtok(line, DELIM);
	while (token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(line), line = NULL;
	command[i] = NULL;
	return (command);
}
