#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	AAnimal* jungle[20];

	// AAnimal IsAbstract;

	for (int i = 0; i < 10; i++)
		jungle[i] = new Cat();
	for (int i = 10; i < 20; i++)
		jungle[i] = new Dog();

	for (int i = 0; i < 20; i++)
		std::cout << jungle[i]->getType() << std::endl;

	std::cout << "\n\33[1;37m/**** Deep Copy ****/\33[0m\n" << std::endl;

	jungle[0]->getBrain()->setIdea( "I doesn't want burn the world!", 0 );
	*(jungle[9]) = *(jungle[0]);

	std::cout << jungle[9]->getType() << " said :\"" 
			<< jungle[9]->getBrain()->getIdea(0) << "\"\n"
			<< std::endl;
	std::cout << "\n\33[1;37m/**** ******** ****/\33[0m\n" << std::endl;


	for (int i = 0; i < 20; i++)
		delete jungle[i];

	return 0;
}