#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "//****************************************************//\n"
		<< "//                                                    //\n"
		<< "//                   Constructor                      //\n"
		<< "//                                                    //\n"
		<< "//****************************************************//\n"
		<< std::endl;

	const Animal* meta = new Animal();
	const Animal* i = new Dog();
	const Animal* j = new Cat();
	const WrongAnimal* k = new WrongAnimal();
	const WrongCat* l = new WrongCat();

	std::cout << "\n//****************************************************//\n"
		<< "//                                                    //\n"
		<< "//                  Type & sound                      //\n"
		<< "//                                                    //\n"
		<< "//****************************************************//\n"
		<< std::endl;

	std::cout << "*****In the forest :*****\n" << std::endl; 
	meta->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); 
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();

	std::cout << "\n*****In the Wrong forest :*****\n" << std::endl; 
	k->makeSound();
	std::cout << l->getType() << " " << std::endl;
	l->makeSound();

	std::cout << "\n//****************************************************//\n"
		<< "//                                                    //\n"
		<< "//                   Copy test                        //\n"
		<< "//                                                    //\n"
		<< "//****************************************************//\n"
		<< std::endl;

	Animal Animale(*i);
	Dog Chien;
	Cat Chat;

	// Chien = Animale;
	// Chat = Chien;
	Animale = Chien;
	std::cout << Animale.getType() << " " << std::endl;
	Animale.makeSound(); 

	std::cout << "\n//****************************************************//\n"
		<< "//                                                    //\n"
		<< "//                   Destructor                       //\n"
		<< "//                                                    //\n"
		<< "//****************************************************//\n"
		<< std::endl;

	delete meta;
	delete i;
	delete j;
	delete k;
	delete l;
}