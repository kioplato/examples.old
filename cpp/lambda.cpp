#include <iostream>   // So we can print using cout.
#include <vector>     // So we can use std::vector objects.
#include <algorithm>  // So we can call std::sort().

#include <functional>

using namespace std;

int main()
{
	// Initialize random number generator.
	srand(10);

	vector<int> v;

	// Add 10 random numbers from [0, 100] range.
	for (unsigned int i = 0; i < 10; ++i)
		v.push_back(rand() % 101);

	// Print unsorted vector.
	cout << "Unsorted vector:" << endl;
	for (auto it : v) cout << '\t' << it << endl;

	// Sort and print the sorted vector in increasing order.
	sort(v.begin(), v.end(), [](Mammal* i, Mammal* j){ return i->get() > j->get_age(); });
	cout << "Sorted vector in decreasing order:" << endl;
	for (auto it : v) cout << it << endl;

	// Sort and print the sorted vector in decreasing order.
	sort(v.begin(), v.end(), [](int i, int j){ return i < j; });
	cout << "Sorted vector in increasing order:" << endl;
	for (auto it : v) cout << it << endl;

	//function<int(int,int)> fn = [=](int i, int j){
	//	for (int it : v) std::cout << it << std::endl;
	//	return i + j;
	//};

	//cout << fn(5, 6) << endl;
}
