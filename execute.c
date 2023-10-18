#include "shell.h"

/**
 * execute - Executes the command specified by the user input. Uses the fork
 * function to create a child process, and the execvp function to execute the
 * command in the child process. Waits for the child process to complete using
 * the waitpid function.
 *
 * @args: Array of strings.
 *
 * Return: Void.
 */
void execute(char **args)
{
pid_t pid = fork();

if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("shell");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("shell");
}
else
{
waitpid(pid, NULL, 0);
}
}
