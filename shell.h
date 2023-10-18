#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void init(void);

char *read_input(void);
char **parse_input(char *input);

void execute(char **args);

int lsh_cd(char **args);
int lsh_help(void);
int lsh_exit(void);

#endif

