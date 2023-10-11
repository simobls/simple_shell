#include "main.h"

int CopyTokens(char *line_copy, const char* delim, char **argv){
	int i = 0;
	char *token = strtok(line_copy, delim);

		while (token != NULL)
		{
			argv[i] = strdup(token); /* Copy each token to the array */
			token = strtok(NULL, delim);
			i++;
		}
		argv[i] = NULL;
		// returns the number of tokens
		return (i);
}
