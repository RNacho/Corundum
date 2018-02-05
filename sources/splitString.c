#include "../headers/splitString.h"

void splitStringWith(char ***output, char *input, char *delimiter)
{
	int position = 0;
	char *line = calloc(strlen(input)+1, sizeof(char));
	char *token = NULL;

	memcpy(line, input, strlen(input)+1);

	token = strtok(line, delimiter);

	for(position = 0; token != NULL; position++) {
		**(output + position) = token;
		*output = realloc(*output, (position + 1) * sizeof(char *));
		token = strtok(NULL, delimiter);
	}
	**(output + position) = NULL;

	free(line);
}

void splitString(char ***output, char *input)
{
	splitStringWith(output, input, " \t\r\n\a");
}
