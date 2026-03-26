#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
std::cout << "=== Test 1: Creating and deleting animals ===" << std::endl;
const Animal* j = new Dog();
const Animal* i = new Cat();

delete i;
delete j;

std::cout << std::endl << "=== Test 2: Array of animals ===" << std::endl;
const Animal* animals[4];

animals[0] = new Dog();
animals[1] = new Cat();
animals[2] = new Dog();
animals[3] = new Cat();

std::cout << std::endl << "Making sounds:" << std::endl;
for (int x = 0; x < 4; x++)
{
animals[x]->makeSound();
}

std::cout << std::endl << "Deleting animals:" << std::endl;
for (int x = 0; x < 4; x++)
{
delete animals[x];
}

std::cout << std::endl << "=== Test 3: Testing deep copy ===" << std::endl;
Dog dog1;
Dog dog2 = dog1;

std::cout << std::endl << "dog1 brain address: " << dog1.getBrain() << std::endl;
std::cout << "dog2 brain address: " << dog2.getBrain() << std::endl;

if (dog1.getBrain() != dog2.getBrain())
std::cout << "Deep copy successful!" << std::endl;
else
std::cout << "ERROR: Shallow copy detected!" << std::endl;

std::cout << std::endl << "=== Test 4: Assignment operator ===" << std::endl;
Dog dog3;
dog3 = dog1;

std::cout << std::endl << "dog1 brain address: " << dog1.getBrain() << std::endl;
std::cout << "dog3 brain address: " << dog3.getBrain() << std::endl;

if (dog1.getBrain() != dog3.getBrain())
std::cout << "Deep copy via assignment successful!" << std::endl;
else
std::cout << "ERROR: Shallow copy via assignment detected!" << std::endl;

return 0;
}
