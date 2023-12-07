#include <iostream>
#include <cstring>
#include <vector>

class Mammal {
	std::string scientific_name;
	unsigned int age;
protected:
	std::vector<Mammal*> kids;
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

	virtual void add_kid(Mammal* kid) = 0;

	std::vector<Mammal*> get_kids() const
	{
		return kids;
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

	virtual void add_kid(Mammal* kid)
	{
		Dog* dog = dynamic_cast<Dog*>(kid);

		if (dog == NULL) {
			std::cout << "Wrong animal" << std::endl;
			return;
		}

		kids.push_back(dog);
	}
};

class Cat : public Mammal {
	std::string breed;
	std::string pet_name;
	std::string catius;
public:
	Cat(unsigned int age, std::string breed, std::string pet_name)
		: Mammal("Catius Labius", age), breed(breed), pet_name(pet_name)
	{
		std::cout << "In Cat ctor" << std::endl;
	}

	~Cat()
	{
		std::cout << "In Cat dtor" << std::endl;
	}

	std::string get_breed() const
	{
		return breed;
	}

	std::string get_pet_name() const
	{
		return pet_name;
	}

	std::string get_catius() const
	{
		return catius;
	}

	virtual void add_kid(Mammal* kid)
	{
		Cat* cat = dynamic_cast<Cat*>(kid);

		if (cat == NULL) {
			std::cout << "Wrong animal" << std::endl;
			return;
		}

		kids.push_back(cat);
	}

	//int operator(int)
	//{
	//	.....
	//}
};

int main()
{
	srand(10);

	std::vector<Mammal*> mammals;

	unsigned int n_dogs = 0;
	unsigned int n_cats = 0;

	for (unsigned int i = 0; i < 10; ++i) {
		unsigned int dice = rand() % 2;
		if (dice == 0) {
			mammals.push_back(new Dog(5, "Labrador", "Spot"));
			++n_dogs;
		} else {
			mammals.push_back(new Cat(5, "Sphinx", "Heart"));
			++n_cats;
		}
	}

	// Filter cats and dogs.
	std::vector<Cat*> cats;
	std::vector<Dog*> dogs;
	for (Mammal* it : mammals) {
		if (dynamic_cast<Cat*>(it))
			cats.push_back(static_cast<Cat*>(it));
		else if (dynamic_cast<Dog*>(it))
			dogs.push_back(static_cast<Dog*>(it));
	}

	std::cout << "We created " << n_cats << std::endl;
	std::cout << "Cats vector contains " << cats.size() << " cats" << std::endl;

	std::cout << "We created " << n_dogs << std::endl;
	std::cout << "Dogs vector contains " << dogs.size() << " dogs" << std::endl;

	for (Mammal* it : cats) delete it;
	for (Mammal* it : dogs) delete it;
}
