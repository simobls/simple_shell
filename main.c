#include "main.h"

int main(){
char *prompt = "(MyShell) $ ";
char *line;
size_t n =0;

	printf("%s", prompt);
	getline(&line, &n, stdin);

	free(line);
return (0);
}