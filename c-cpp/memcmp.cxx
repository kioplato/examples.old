#include <iostream>
#include <string.h>

using namespace std;

void buffer1_bigger_than_buffer2()
{
	int buffer1[10];
	for (int i = 0; i < 10; ++i)
		buffer1[i] = 9;

	int buffer2[10];
	for (int i = 0; i < 10; ++i)
		buffer2[i] = 2;

	cout << "buffer1 > buffer2 = " << memcmp(buffer1, buffer2, sizeof(int) * 10) << endl;
}

void buffer1_equal_to_buffer2()
{
	int buffer1[10];
	for (int i = 0; i < 10; ++i)
		buffer1[i] = 5;

	int buffer2[10];
	for (int i = 0; i < 10; ++i)
		buffer2[i] = 5;

	cout << "buffer1 == buffer2 = " << memcmp(buffer1, buffer2, sizeof(int) * 10) << endl;
}

void buffer1_smaller_than_buffer2()
{
	int buffer1[10];
	for (int i = 0; i < 10; ++i)
		buffer1[i] = 0;

	int buffer2[10];
	for (int i = 0; i < 10; ++i)
		buffer2[i] = 5;

	cout << "buffer1 < buffer2 = " << memcmp(buffer1, buffer2, sizeof(int) * 10) << endl;
}

void negative_buffer1_bigger_than_buffer2()
{
	int buffer1[10];
	for (int i = 0; i < 10; ++i)
		buffer1[i] = -1;

	int buffer2[10];
	for (int i = 0; i < 10; ++i)
		buffer2[i] = 0;

	cout << "buffer1 > buffer2 = " << memcmp(buffer1, buffer2, sizeof(int) * 10) << endl;
}

int main()
{
	buffer1_bigger_than_buffer2();
	buffer1_equal_to_buffer2();
	buffer1_smaller_than_buffer2();

	cout << "Be careful about this case:" << endl;
	negative_buffer1_bigger_than_buffer2();
}
