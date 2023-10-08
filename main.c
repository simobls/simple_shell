#include "main.h"

int main(){
	char *prompt = "(MyShell) $ ";
	char *line;
	size_t n =0;
	ssize_t n_char;

//infinite loop
	while (true)
	{
		printf("%s", prompt);
		// use ctrl-d to send an EOF - returns -1
		n_char = getline(&line, &n, stdin);

// condition to exit MyShell - break the infinite loop

		if (n_char == -1)
		{
			printf("Exit MyShell ...\n");
			return (-1);
		}

		printf("%s", line);
// free allocated memory
		free(line);
	}
		
return (0);
}
