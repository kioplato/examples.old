#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
	uint32_t *buffer = malloc(sizeof(uint32_t) * 10);

	for (uint32_t index = 0; index < 10; ++index)
		buffer[index] = index * index;

	for (uint32_t index = 0; index < 10; ++index)
		cout << buffer[index] << endl;

	free(buffer);
}
