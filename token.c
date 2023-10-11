#include "main.h"

int NumberOfTokens(char *token, const char* delim){
	int num_tokens = 0;

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	return (num_tokens);
}

void CopyTokens(char *token, const char* delim, char **argv){
	int i = 0;

		while (token != NULL)
		{
			argv[i] = strdup(token); /* Copy each token to the array */
			token = strtok(NULL, delim);
			i++;
		}
}