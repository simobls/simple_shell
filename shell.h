#ifndef SHELL_H
#define SHELL_H

/**
 * This is the shell header file.
 * It contains the function prototypes and necessary includes for the shell.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \t\n"

/**
 * Function to read a line from the input (stdin).
 * @return A pointer to the read line.
 */
char *read_the_line(void);

/**
 * Function to duplicate a string (similar to strdup).
 * @param str The input string.
 * @return A pointer to the duplicated string.
 */
char *_strdup(const char *str);

/**
 * Function to compare two strings.
 * @param s1 The first string.
 * @param s2 The second string.
 * @return The comparison result.
 */
int _strcmp(char *s1, char *s2);

/**
 * Function to calculate the length of a string.
 * @param s The input string.
 * @return The length of the string.
 */
int _strlen(char *s);

/**
 * Function to concatenate two strings.
 * @param dest The destination string.
 * @param src The source string.
 * @return The concatenated string.
 */
char *_stecat(char *dest, char *src);

/**
 * Function to copy a string.
 * @param dest The destination string.
 * @param src The source string.
 * @return The copied string.
 */
char *_strcpy(char *dest, char *src);

/**
 * Function to tokenize a line into an array of strings.
 * @param line The input line.
 * @return An array of tokens.
 */
char **tokenizer(char *line);

extern char **environ;

/**
 * Function to free a 2D array of strings.
 * @param arr The array to be freed.
 */
void free2Darray(char **arr);

/**
 * Function to execute a command.
 * @param command The command to be executed.
 * @param argv The argument vector.
 * @return The exit status of the executed command.
 */
int execute_(char **command, char **argv, int idx);

/**
 * Function to get the value of an environment variable.
 * @param variable The name of the environment variable.
 * @return The value of the environment variable.
 */
char *_getenv(char *variable);

/**
 * Function to get the full path of a command.
 * @param command The command to find the path for.
 * @return The full path of the command, or NULL if not found.
 */
char *_get_the_path(char *command);

/**
 * Function to print an error message.
 * @param name The name of the program.
 * @param cmd The command causing the error.
 * @param idx The index of the command.
 */
void print_the_error(char *name, char *cmd, int idx);

/**
 * Function to convert an integer to a string.
 * @param n The integer to convert.
 * @return The converted string.
 */
char *_itoa(int n);

/**
 * Function to reverse a string.
 * @param str The string to reverse.
 * @param len The length of the string.
 */
void reverse_the_string(char *str, int len);

/**
 * is_builtin - Check if a command is a built-in shell command.
 * @command: The command to check.
 *
 * Return: 1 if it's a built-in command, 0 otherwise.
 */
int is_builtin(char *command);

/**
 * handle_builtin - Handle the execution of built-in shell commands.
 * @command: The command to execute.
 * @argv: The argument vector.
 * @status: The exit status of the command.
 * @idx: The command index.
 */
void handle_builtin(char **command, char **argv, int *status, int idx);

/**
 * exit_shell - Handle the built-in "exit" command.
 * @command: The command to execute.
 * @argv: The argument vector.
 * @status: The exit status of the command.
 * @idx: The command index.
 */
void exit_shell(char **command, char **argv, int *status, int idx);

/**
 * print_env - Handle the built-in "env" command.
 * @command: The command to execute.
 * @status: The exit status of the command.
 */
void print_env(char **command, int *status);

/**
 * positive_num - Check if a string represents a positive number.
 * @str: The input string to check.
 *
 * Return: 1 if it's a positive number, 0 otherwise.
 */
int positive_num(char *str);

/**
 * _atoi - Convert a string to an integer.
 * @str: The string to convert.
 *
 * Return: The integer value of the string.
 */
int _atoi(char *str);


#endif
