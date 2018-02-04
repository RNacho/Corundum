#include "../headers/splitString.h"

char **splitStringWith(char *input, char *delimiter)
{
	char *line = calloc(1, sizeof(input));
	int bufsize = 1, position = 0;
	char **tokens = calloc(bufsize, sizeof(char *));
	char *token;

	memcpy(line, input, strlen(input)+1);

	if (!tokens || !line) {
		fprintf(stderr, "\nAllocation failure in splitString.c\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delimiter);
	while (token != NULL) {
		tokens[position] = token;
		position++;

		if (position >= bufsize) {
			bufsize += 1;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens) {
				fprintf(stderr,
					"\nAllocation failure in splitString.c\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, delimiter);
	}
	tokens[position] = NULL;
	return tokens;
}

char **splitString(char *input)
{
	return splitStringWith(input, " \t\r\n\a");
}
