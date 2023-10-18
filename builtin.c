#include "shell.h"

int lsh_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "shell: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("shell");
        }
    }
    return 1;
}

int lsh_help() {
    printf("shell - a simple shell program\n");
    printf("Commands:\n");
    printf("cd [dir] - change directory\n");
    printf("exit - exit the shell\n");
    printf("help - display this help message\n");
    return 1;
}
int lsh_exit() {
    return 0;
}