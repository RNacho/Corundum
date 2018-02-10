/* This is just a dummy main intended for test
 * of the library itself, if you plan to compile
 * the library from source, follow the instructions
 * at readme, do not compile this main
 */

#include "../headers/Corundum.h"

int main(void)
{
	size_t i = 0;
	size_t argumentCount = 0;
	//size_t argumentCountWith = 0;
	char *input = NULL;
	//char *delimiter = NULL;
	char **arguments = NULL;
	//char **argumentsWith = NULL;

	input = calloc(1, sizeof(char));
	arguments = calloc(1, sizeof(char *));
	*arguments = calloc(1, sizeof(char));
	//argumentsWith = calloc(1, sizeof(char *));
	//*argumentsWith = calloc(1, sizeof(char));

	readStdin(&input);
	puts("Este es el input:");
	puts(input);

	argumentCount = splitString(&input, &arguments);
	printf("Este es el argcount nuevo: %ld\n", argumentCount);

	puts("Estos son los argumentos nuevos:");
	for (i = 0; i < argumentCount; i++)
		puts(*(arguments + i));


	for (i = 0; i < argumentCount; i++)
		memset(*(arguments + i), '\0', strlen(*(arguments + i)));

	free(input);
	input = NULL;
	
	for (i = 0; i < argumentCount; i++) {
		free(*(arguments + i));
		*(arguments + i) = NULL;
	}
	
	free(arguments);
	arguments = NULL;

	return EXIT_SUCCESS;
}
