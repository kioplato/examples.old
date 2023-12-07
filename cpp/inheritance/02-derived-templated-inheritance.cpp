#include <iostream>
#include <cstring>

class Mammal {
	std::string scientific_name;
	unsigned int age;
public:
	Mammal(std::string scientific_name, unsigned int age)
		: scientific_name(scientific_name), age(age)
	{
		std::cout << "In Mammal constructor" << std::endl;
	}

	std::string get_scientific_name() const
	{
		return scientific_name;
	}

	unsigned int get_age() const
	{
		return age;
	}

	void birthday()
	{
		++age;
	}
};

template <typename T>
class Dog : public Mammal {
	std::string breed;
	std::string pet_name;

	T* buffer;
public:
	Dog(unsigned int age, std::string breed, std::string pet_name)
		: Mammal("Canis familiaris", age), breed(breed), pet_name(pet_name), buffer(new T[10])
	{
		std::cout << "In Dog ctor" << std::endl;

		//memset(buffer, 0, sizeof(T) * 10);

		for (unsigned int i = 0; i < 10; ++i)
			buffer[i] = 0;
	}

	~Dog()
	{
		std::cout << "In Dog dtor" << std::endl;

		delete [] buffer;
	}

	std::string get_breed() const
	{
		return breed;
	}

	std::string get_pet_name() const
	{
		return pet_name;
	}

	T& operator [] (size_t index)
	{
		return buffer[index];
	}
};

int main()
{
	Dog<int> dog(5, "Labrador", "Spot");

	std::cout << dog.get_scientific_name() << std::endl;
	std::cout << dog.get_age() << std::endl;
	dog.birthday();
	std::cout << dog.get_age() << std::endl;

	dog[5] = 8;
}
