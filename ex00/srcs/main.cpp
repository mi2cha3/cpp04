#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== Testing correct polymorphism ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << std::endl << "j->getType(): " << j->getType() << std::endl;
	std::cout << "i->getType(): " << i->getType() << std::endl;
	std::cout << std::endl;
	
	std::cout << "i->makeSound():" << std::endl;
	i->makeSound(); //will output the cat sound!
	
	std::cout << std::endl << "j->makeSound():" << std::endl;
	j->makeSound();
	
	std::cout << std::endl << "meta->makeSound():" << std::endl;
	meta->makeSound();
	
	std::cout << std::endl << "Deleting animals..." << std::endl;
	delete i;
	delete j;
	delete meta;

	std::cout << std::endl << "=== Testing wrong polymorphism ===" << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_i = new WrongCat();
	
	std::cout << std::endl << "wrong_i->getType(): " << wrong_i->getType() << std::endl;
	std::cout << std::endl;
	
	std::cout << "wrong_i->makeSound() (should be WrongAnimal sound, not WrongCat):" << std::endl;
	wrong_i->makeSound(); //will output the WrongAnimal sound because no virtual keyword!
	
	std::cout << std::endl << "wrong_meta->makeSound():" << std::endl;
	wrong_meta->makeSound();
	
	std::cout << std::endl << "Deleting wrong animals..." << std::endl;
	delete wrong_i;
	delete wrong_meta;
	
	return 0;
}
