/**
 * Description: C++ provides data structures that don't have their own find
 * function in order to find an element in a set or vector to call erase on it.
 * To perform that operation we need find() function from algorithm library.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main()
{
	// Create a vector in stack.
	std::vector<int> v;

	// Initialize the random number generator.
	srand(10);

	// Insert 10 random positive numbers in the vector from [0, 100] range.
	for (unsigned int i = 0; i < 10; ++i)
		v.push_back(rand() % 101);

	std::vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); ++iter)
		if ((*iter) == 5)
			break;
	//
	v.erase(std::find(v.begin(), v.end(), 5));

	// Find a random position in the vector.
	std::vector<int>::iterator position = v.begin() + rand() % 11;

	// Insert a negative integer so we can find it later.
	// Insert function inserts before the item that the iterator points.
	v.insert(position, -1);

	// Find the -1 we inserted at an unknown index.
	if (std::find(v.begin(), v.end(), -1) != v.end())
		std::cout << "We found -1" << std::endl;
	else
		std::cout << "We didn't find -1" << std::endl;

	// Try to find a number that does not exist.
	if (std::find(v.begin(), v.end(), -2) != v.end())
		std::cout << "We found -2" << std::endl;
	else
		std::cout << "We didn't find -2" << std::endl;
}
