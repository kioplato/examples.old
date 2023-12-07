#include <iostream>
#include <cstdint>

class ClassA {
	std::string _str;

public:
	ClassA(std::string str) : _str(str)
	{
		// Empty.
	}

	const std::string& get_str() const
	{
		return _str;
	}
};

class ClassB {
public:
	ClassB(const ClassA& classA)
	{
		std::cout << classA.get_str() << std::endl;
	}
};

int main()
{
	ClassB classB(std::string("abc"));
}
