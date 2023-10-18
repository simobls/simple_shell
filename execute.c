#include "shell.h"

/**
 * execute_ - Execute a command in a child process.
 * @command: The command to execute.
 * @argv: The argument vector.
 * @idx: The index of the command.
 *
 * Return: The exit status of the executed command.
 */
int execute_(char **command, char **argv, int idx)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = _get_the_path(command[0]);

	if (!full_cmd)
	{
		print_the_error(argv[0], command[0], idx);
		free2Darray(command);
		return (127);
	}

	child = fork();

	if (child == 0)
	{
		/* Child process */
		if (execve(full_cmd, command, environ) == -1)
		{
			free(full_cmd);
			free2Darray(command);
		}
	}
	else
	{
		/* Parent process */
		waitpid(child, &status, 0);
		free2Darray(command);
		free(full_cmd);
	}

	return (WEXITSTATUS(status));
}
