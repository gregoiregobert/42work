#include "PhoneBook.class.hpp"

void	ft_add(PhoneBook *PhoneBook)
{
	std::string	tmp;

	std::cout << "First name  :" << std::endl;
	std::cin >> tmp;
	std::cout << tmp << std::endl;
	while ()
	{
		std::cout << "He/she don't have name?" << std::endl;
		std::cin >> tmp;
	}
	PhoneBook->tel[0].first_name = tmp;
}

int	main()
{
	PhoneBook	phonebook;
	std::string	istream;

	while (istream != "EXIT")
	{
		std::cout << "menu" << std::endl;
		std::cin >> istream;
		if (istream == "ADD")
			ft_add(&phonebook);
	}
}
