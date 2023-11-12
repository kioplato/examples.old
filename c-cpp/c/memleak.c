/**
 * Purpose: Create a memory leak of 400 bytes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
	uint32_t *buffer = NULL;
	size_t size = sizeof(uint32_t) * 100;
	if ((buffer = malloc(size)) == NULL)
		exit(EXIT_FAILURE);

	return EXIT_SUCCESS;
}
