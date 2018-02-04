#include "../headers/master.h"

int main(void)
{
	char *stringStdin = readStdin();

	printf("Read: %s", stringStdin);
	free(stringStdin);

	return EXIT_SUCCESS;
}
