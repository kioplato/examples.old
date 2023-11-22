/**
 * Purpose: Demonstrate cache locality.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int main()
{
	srand(100);

	uint32_t size = 10e6;

	// Block of memory with 1_000_000 uint32_t.
	uint32_t* buffer = calloc(size, sizeof(uint32_t));

	// Populate random indices of @buffer block with random values.
	for (uint32_t c_iter = 0; c_iter < size; ++c_iter) {
		uint32_t index = rand() % (uint32_t)size;
		uint32_t value = rand() % (uint32_t)size;

		buffer[index] = value;
	}

	// Print random indices from @buffer.
	for (uint32_t c_iter = 0; c_iter < size; ++c_iter) {
		uint32_t index = rand() % (uint32_t)size;

		printf("buffer[%d] = %d\n", index, buffer[index]);
	}

	free(buffer);
}
