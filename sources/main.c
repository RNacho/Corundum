/* This is just a dummy main intended for test
 * of the library itself, if you plan to compile
 * the library from source, follow the instructions
 * at readme, do not compile this main
 */

#include "../headers/Corundum.h"

int main(void)
{
	puts("");
	puts("Start");
	puts("");

	puts("Receiving input: ");
	char *stringStdin = readStdin();

	puts("");

	puts("Read with readStdin: ");
	puts(stringStdin);

	int i = 0;
	char **stringTokens = splitString(stringStdin);
	
	char **stringTokensWith = splitStringWith(stringStdin, "d");

	puts("");
	puts("Tokenized with splitString:");

	for(i=0; stringTokens[i] != NULL; i++){
		printf("Element number [%d]: ", i);
		puts(stringTokens[i]);
	}

	puts("");
	puts("Tokenized with splitStringWith(\"d\"):");

	for(i=0; stringTokensWith[i] != NULL; i++){
		printf("Element number [%d]: ", i);
		puts(stringTokensWith[i]);
	}
	free(stringStdin);

	puts("");
	puts("End");
	puts("");

	return EXIT_SUCCESS;
}
