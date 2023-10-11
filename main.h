#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int CopyTokens(char *token, const char* delim, char **argv);
void display_prompt();
void execute_command(char *args[]);