#include "shell.h"

/**
 * print_the_error - Print an error message to stderr.
 * @name: The name of the program.
 * @cmd: The command that resulted in an error.
 * @idx: The index of the command.
 */
void print_the_error(char *name, char *cmd, int idx)
{
	char *index, msg[] = ": not found\n";

	index = _itoa(idx);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));
	free(index);
}

/**
 * _itoa - Convert an integer to a string.
 * @n: The integer to convert.
 * Return: A string representation of the integer.
 */
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	reverse_the_string(buffer, i);
	return (_strdup(buffer));
}

/**
 * reverse_the_string - Reverse a string in-place.
 * @str: The string to reverse.
 * @len: The length of the string.
 */
void reverse_the_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
/**
 * positive_num - Check if a string represents a positive number.
 * @str: The string to check.
 *
 * Return: 1 if the string is a positive number, 0 otherwise.
 */
int positive_num(char *str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _atoi - Convert a string to an integer.
 * @str: The string to convert.
 *
 * Return: The integer representation of the string.
 */
int _atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i]; i++)
	{
		num = num * 10 + (str[i] - '0');
	}
	return (num);
}
