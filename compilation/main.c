/* This is just a dummy main intended for test
 * of the library itself, if you plan to compile
 * the library from source, follow the instructions
 * at readme, do not compile this main
 */

#include "../headers/master.h"

int main(void)
{
	char *stringStdin = readStdin();

	printf("Read: %s", stringStdin);
	free(stringStdin);

	return EXIT_SUCCESS;
}
