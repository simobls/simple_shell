#include "shell.h"

char *read_input(void) {
    char *input = NULL;
    size_t size = 0;
    getline(&input, &size, stdin);
    input[strcspn(input, "\n")] = '\0';
    return input;
}
char **parse_input(char *input) {
    char **args = malloc(64 * sizeof(char *));
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
    return args;
}