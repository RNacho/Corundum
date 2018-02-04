/* This is just a dummy main intended for test
 * of the library itself, if you plan to compile
 * the library from source, follow the instructions
 * at readme, do not compile this main
 */

#include "../headers/master.h"

int main(void)
{
	puts("");
	puts("Start");
	puts("");

	printf("Reading input: ");
	char *stringStdin = readStdin();

	char **stringTokens = splitString(stringStdin);
	int i = 0;

	puts("");

	puts("Read with readStdin: ");
	puts(stringStdin);

	puts("");
	puts("Tokenized with splitString:");

	for(i=0; stringTokens[i] != NULL; i++){
		printf("Element number [%d]: ", i);
		puts(stringTokens[i]);
	}

	free(stringStdin);

	puts("");
	puts("End");
	puts("");

	return EXIT_SUCCESS;
}
