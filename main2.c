#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 64

void display_prompt() {
    printf("myshell> ");
    fflush(stdout);
}

int parse_input(char *input, char *args[]) {
    int arg_count = 0;
    char *token = strtok(input, " \t\n");

    while (token != NULL) {
        args[arg_count] = token;
        arg_count++;

        token = strtok(NULL, " \t\n");
    }

    args[arg_count] = NULL; // Null-terminate the array
    return arg_count;
}

void execute_command(char *args[]) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Command execution error");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("Fork error");
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARG_SIZE];
    int arg_count;

    while (1) {
        display_prompt();

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\n");
            break;
        }

        arg_count = parse_input(input, args);

        if (arg_count > 0) {
            if (strcmp(args[0], "exit") == 0) {
                // Handle the 'exit' command
                exit(0);
            } else if (strcmp(args[0], "cd") == 0) {
                // Handle the 'cd' command
                if (arg_count == 2) {
                    if (chdir(args[1]) != 0) {
                        perror("cd");
                    }
                } else {
                    fprintf(stderr, "Usage: cd <directory>\n");
                }
            } else {
                execute_command(args);
            }
        }
    }

    return 0;
}

