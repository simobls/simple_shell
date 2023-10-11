#include "main.h"

int main(int argc, char **argv)
{
	char *prompt = "(MyShell) $ "; /* declaration of variables */
	char *line;
	size_t n = 0;
	int n_char;
	const char *delim = " \n";
	(void)argc, (void)argv; /* cast void on arguments */

	while (true) /* infinite loop */
	{
		printf("%s", prompt); /* print the prompt */
		n_char = getline(&line, &n, stdin); /* use ctrl-d to send an EOF */
		if (n_char == -1) /* condition to exit MyShell - break the infinite loop */
		{
			printf("Exit MyShell ...\n");
			return (-1);
		}
		printf("command : %s", line);
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
		int num_tokens = NumberOfTokens(token, delim); /*calculate number of tokens*/

		printf("number of tokens : %d\n", num_tokens);
		char **argv = (char **)malloc(num_tokens * sizeof(char *));

		line_copy = strdup(line);
		token = strtok(line_copy, delim);

		CopyTokens(token, delim, argv);
		for (int i = 0; i < num_tokens; i++) /* print the tokens */
			printf("token %d : %s\n", i, argv[i]);

		for (int i = 0; i < num_tokens; i++)
			free(argv[i]);
		free(argv);
		free(line_copy);
	}
	free(line); /* free allocated memory for the command */
	return (0);
}
