#include <iostream>
#include <cstring>

template <typename T>
class Mammal {
	std::string scientific_name;
	unsigned int age;

	T data;
public:
	Mammal(std::string scientific_name, unsigned int age)
		: scientific_name(scientific_name), age(age)
	{
		std::cout << "In Mammal constructor" << std::endl;
	}

	~Mammal()
	{
		std::cout << "In Mammal dtor" << std::endl;
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

	T get_data() const
	{
		return data;
	}

	void set_data(T data_in)
	{
		data = data_in;
	}
};

class Dog : public Mammal<int> {
	std::string breed;
	std::string pet_name;
public:
	Dog(unsigned int age, std::string breed, std::string pet_name)
		: Mammal<int>("Canis familiaris", age), breed(breed), pet_name(pet_name)
	{
		std::cout << "In Dog ctor" << std::endl;
	}

	~Dog()
	{
		std::cout << "In Dog dtor" << std::endl;
	}

	std::string get_breed() const
	{
		return breed;
	}

	std::string get_pet_name() const
	{
		return pet_name;
	}
};

int main()
{
	Dog dog(5, "Labrador", "Spot");

	std::cout << dog.get_scientific_name() << std::endl;
	std::cout << dog.get_age() << std::endl;
	dog.birthday();
	std::cout << dog.get_age() << std::endl;

	dog.set_data(500);
	std::cout << dog.get_data() << std::endl;

	return EXIT_SUCCESS;
}
