#include "main.h"

int main(int argc, char **argv)
{
/* declaration of variables */
	char *prompt = "(MyShell) $ ";
	char *line;
	size_t n = 0;
	int n_char;
	const char *delim = " \n";

/* cast void on arguments */
	(void)argc, (void)argv;

/* infinite loop */
	while (true)
	{
	/* print the prompt */
		printf("%s", prompt);
	/* use ctrl-d to send an EOF - returns -1 */
		n_char = getline(&line, &n, stdin);

	/* condition to exit MyShell - break the infinite loop */
		if (n_char == -1)
		{
			printf("Exit MyShell ...\n");
			return (-1);
		}
		printf("command : %s", line);

	/* make a copy of the command after allocating the memory */
		char *line_copy = malloc(sizeof(char) * n_char);

		if (line_copy == NULL)
		{
			perror("tsh : memory allocation error");
			return (-1);
		}
		strcpy(line_copy, line);
		printf("copy of the command : %s\n", line_copy);

	/* parse - tokenize - the command we copied */
		char *token = strtok(line_copy, delim);

		/* calculate number of tokens */
		int num_tokens = 0;

		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		printf("number of tokens : %d\n", num_tokens);

		/* storing the tokens */
		char **argv = (char **)malloc(num_tokens * sizeof(char *));
		line_copy = strdup(line);
		token = strtok(line_copy, delim);

		int i = 0;

		while (token != NULL)
		{
			argv[i] = strdup(token); /* Copy each token to the array */
			token = strtok(NULL, delim);
			i++;
		}
		/* print the tokens */
		for (i = 0; i < num_tokens; i++)
			printf("token %d : %s\n", i, argv[i]);

		/* free memory for the command copy and the tokens we made */
		for (i = 0; i < num_tokens; i++)
			free(argv[i]);

		free(argv);
		free(line_copy);
	}
	/* free allocated memory for the command */
	free(line);
	return (0);
}
