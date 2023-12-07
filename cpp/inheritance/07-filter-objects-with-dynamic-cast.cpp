#include <iostream>
#include <vector>

class Mammal {
	// The scientific name of the mammal.
	std::string scientific_name;

	// The age of the mammal.
	unsigned int age;

public:
	Mammal(std::string scientific_name, unsigned int age)
		: scientific_name(scientific_name), age(age)
	{
		// Empty.
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

class Cat : public Mammal {
	std::string breed;
	std::string pet_name;

public:
	Cat(unsigned int age, std::string breed, std::string pet_name)
		: Mammal("Catius Labius", age), breed(breed), pet_name(pet_name)
	{
		// Empty.
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

class Dog : public Mammal {
	std::string breed;
};

int main()
{
	srand(10);

	// Vector that will contain all created mammals.
	std::vector<Mammal*> mammals;

	// The number of cats and dogs we created.
	unsigned int n_cats = 0;
	unsigned int n_dogs = 0;

	// Create 10 cats and dogs.
	for (unsigned int i = 0; i < 10; ++i) {
		if (rand() % 2) {
			mammals.push_back(new Dog("Canis familiaris", 5, "Labrador", "Spot"));
			++n_dogs;
		} else {
			mammals.push_back(new Cat(""));
			++n_cats;
		}
	}
}
