/* Usage of this function
 *
 * char *stringStdin = readStdin();
 *
 * ... use of the stringStdin variable ...
 *
 * free(stringStdin);
 */


#include "../headers/readStdin.h"

char *readStdin(void)
{
	char *input = NULL;
	char buffer[2];
	size_t inputLength = 0, bufferLength = 0;

	do {
		fgets(buffer, 2, stdin);
		bufferLength = strlen(buffer);
		inputLength += bufferLength;
		input = realloc(input, inputLength+1);
		strcat(input, buffer);
	} while (bufferLength == 1 && buffer[0] != '\n');

	return input;
}
