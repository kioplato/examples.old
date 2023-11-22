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

	// Populate sequential indices of @buffer block with random values.
	for (uint32_t index = 0; index < size; ++index) {
		uint32_t value = rand() % (uint32_t)size;

		buffer[index] = value;
	}

	// Print sequential indices from @buffer.
	for (uint32_t index = 0; index < size; ++index)
		printf("buffer[%d] = %d\n", index, buffer[index]);

	free(buffer);
}
