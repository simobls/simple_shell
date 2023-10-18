#include "shell.h"

/**
 * lsh_cd - Changes the current working directory of the shell program. Takes
 * an array of strings as input, where the first string is the command name and
 * the second string is the directory to change to.
 *
 * @args: Array of strings.
 *
 * Return: Integer.
 */
int lsh_cd(char **args)
{
if (args[1] == NULL)
fprintf(stderr, "shell: expected argument to \"cd\"\n");
else
{
if (chdir(args[1]) != 0)
perror("shell");
}
return (1);
}

/**
 * lsh_help - Displays a help message for the shell program. Takes an array of
 * strings as input, where the first string is the command name.
 *
 * @args: Array of strings.
 *
 * Return: Integer.
 */
int lsh_help(void)
{
	printf("shell - a simple shell program\n");
	printf("Commands:\n");
	printf("cd [dir] - change directory\n");
	printf("exit - exit the shell\n");
	printf("help - display this help message\n");
	return (1);
}

/**
 * lsh_exit - Exits the shell program. Takes an array of strings as input,
 * where the first string is the command name.
 *
 * @args: Array of strings.
 *
 * Return: Integer.
 */
int lsh_exit(void)
{
	return (0);
}
