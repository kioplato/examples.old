#include <iostream>

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

class Dog : public Mammal {
	std::string breed;
	std::string pet_name;
public:
	Dog(unsigned int age, std::string breed, std::string pet_name)
		: Mammal("Canis familiaris", age), breed(breed), pet_name(pet_name)
	{
		std::cout << "In Dog constructor" << std::endl;
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
}
