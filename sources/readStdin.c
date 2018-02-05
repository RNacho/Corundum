#include "../headers/readStdin.h"

void readStdin(char **output)
{
	char buffer[2];
	size_t inputLength = 0, bufferLength = 0;

	do {
		fgets(buffer, 2, stdin);
		bufferLength = strlen(buffer);
		inputLength += bufferLength;
		*output = realloc(*output, inputLength+1);
		strcat(*output, buffer);
	} while (bufferLength == 1 && buffer[0] != '\n');

	strtok(*output, "\n");
}
