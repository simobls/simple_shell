#include "shell.h"

/**
 * _get_the_path - Get the full path of a command.
 * @command: The command to find the path for.
 *
 * Return: The full path of the command, or NULL if not found.
 */
char *_get_the_path(char *command)
{
	char *path_env, *full_cmd, *direc;
	int i;
	struct stat st;

	/* If the command is already a path */
	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0) /* If path exists */
				return (_strdup(command));
			return (NULL);
	}
	}

	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);

	direc = strtok(path_env, ":");
	while (direc)
	{
		full_cmd = malloc(_strlen(direc) + _strlen(command) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, direc);
			_stecat(full_cmd, "/");
			_stecat(full_cmd, command);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd);
			full_cmd = NULL;
			direc = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
