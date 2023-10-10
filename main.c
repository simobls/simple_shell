#include "main.h"

int main(int argc, char **argv){
// declaration of variables
	char *prompt = "(MyShell) $ ";
	char *line = NULL, *line_copy = NULL, *token;
	const char *delim = " \n";
	size_t n = 0;
	int n_char;
	int num_token;

// cast void on the arguments of the main
	(void)argc, (void)argv;

// infinite loop
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

	//make a copy of the command after allocationg space
		line_copy = malloc(sizeof(char)*n_char);
		if (line_copy == NULL)
		{
			perror("tsh : memory allocation error\n");
			return (-1);
		}
		strcpy(line_copy, line);
	
	// parse - tokenize - the command we copied
		token = strtok(line_copy, delim);

		// calculate the number of tokens
		while (token != NULL)
		{
			num_token++;
			token = strtok(NULL, delim); // we call strtok() with a NULL argument to make it continue tokenizing from it's previous position
		}
		num_token++;

		token = strtok(line_copy, delim);

		int i = 0;
		while (token != NULL)
		{
			argv[i] = malloc(sizeof(char)*strlen(token));
			strcpy(argv[i], token);
			i++;

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		for (i = 0; i < num_token; i++)
		{
			printf("%s\n", argv[i]);
		}

	// free allocated memory
		free(argv);
		free(line_copy);
	}
	free(line);
	return (0);
}
