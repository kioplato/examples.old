#include <iostream>
#include <cstring>

class Mammal {
	std::string scientific_name;
	unsigned int age;
public:
	Mammal(std::string scientific_name, unsigned int age)
		: scientific_name(scientific_name), age(age)
	{
		std::cout << "In Mammal ctor" << std::endl;
	}

	virtual ~Mammal()
	{
		std::cout << "In Mammal dtor" << std::endl;
	}

	std::string get_scientific_name() const
	{
		return scientific_name;
	}

	virtual unsigned int get_age() const
	{
		std::cout << "In get_age of Mammal" << std::endl;
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

	int* buffer;
public:
	Dog(unsigned int age, std::string breed, std::string pet_name)
		: Mammal("Canis familiaris", age), breed(breed), pet_name(pet_name), buffer(new int[10])
	{
		std::cout << "In Dog ctor" << std::endl;
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

	unsigned int get_age() const
	{
		std::cout << "In get_age of Dog" << std::endl;
		return 1000;
	}
};

//class Cat : public Mammal {
//	std::string breed;
//	std::string pet_name;
//	std::string catius;
//public:
//	Cat(unsigned int age, std::string breed, std::string pet_name)
//		: Mammal("Catius Labius", age), breed(breed), pet_name(pet_name)
//	{
//		std::cout << "In Dog ctor" << std::endl;
//	}
//
//	~Cat()
//	{
//		std::cout << "In Dog dtor" << std::endl;
//	}
//
//	std::string get_breed() const
//	{
//		return breed;
//	}
//
//	std::string get_pet_name() const
//	{
//		return pet_name;
//	}
//
//	std::string get_catius() const
//	{
//		return catius;
//	}
//};

int main()
{
	Mammal* mammal = new Dog(5, "Labrador", "Spot");

	mammal->get_age();

	delete mammal;
}
