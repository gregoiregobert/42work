#include "PhoneBook.class.hpp"

int	str_isdigit(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!isdigit(str[i]))
			return (0);
	return (1);
}

std::string	cut_at_ten(std::string str)
{
	std::string	tmp;
	std::string space;

	tmp = str;
	space = "          ";
	if (str.size() > 10)
	{
		tmp = str.substr(0, 10);
		tmp [9] = '.';
	}
	if (str.size() < 10)
	{
		tmp = str.append(space);
		tmp = tmp.substr(0, 10);
	}
	return (tmp);
}

void	ft_display_contact(int i, PhoneBook *phbook)
{
	std::cout << "First name	: " << phbook->getContactFirst_name(i) << std::endl;
	std::cout << "Last name	: "  << phbook->getContactLast_name(i) << std::endl;
	std::cout << "Nickname	: "  << phbook->getContactNickname(i) << std::endl;
	std::cout << "Number		: "  << phbook->getContactNumber(i) << std::endl;
	std::cout << "Darkest secret	: "  << phbook->getContactDarkest_secret(i) << std::endl;
}

void	ft_search(PhoneBook *phbook)
{
	int			i;
	int			index;
	std::string tmp;

	i = -1;
	while (++i < 8)
	{
		std::cout << i
		<< "|" << cut_at_ten(phbook->getContactFirst_name(i))
		<< "|" << cut_at_ten(phbook->getContactLast_name(i))
		<< "|" << cut_at_ten(phbook->getContactNickname(i))
		<< std::endl;
	}
	std::cout << "Type index of contact you want to see" << std::endl;
	std::getline(std::cin, tmp, '\n');
	index = atoi(tmp.c_str());
	if (index > 7 || index < 0 || !str_isdigit(tmp.c_str()) || tmp.length() == 0)
		std::cout << "Index does't exist" << std::endl;
	else
		ft_display_contact(index, phbook);
}

void	ft_add(PhoneBook *phbook)
{
	std::string	tmp;

	std::cout << "First name:" << std::endl;
	std::getline(std::cin, tmp, '\n');
	while (tmp.length() == 0)
	{
		std::cout << "Can't be empty" << std::endl;
		std::getline(std::cin, tmp, '\n');
	}
	phbook->setContactFirst_name(tmp, phbook->getIndex());

	std::cout << "Last name:" << std::endl;
	std::getline(std::cin, tmp, '\n');
	while (tmp.length() == 0)
	{
		std::cout << "Can't be empty" << std::endl;
		std::getline(std::cin, tmp, '\n');
	}
	phbook->setContactLast_name(tmp, phbook->getIndex());

	std::cout << "Nickname:" << std::endl;
	std::getline(std::cin, tmp, '\n');
	while (tmp.length() == 0)
	{
		std::cout << "Can't be empty" << std::endl;
		std::getline(std::cin, tmp, '\n');
	}
	phbook->setContactNickname(tmp, phbook->getIndex());

	std::cout << "Number:" << std::endl;
	std::getline(std::cin, tmp, '\n');
	while (tmp.length() == 0)
	{
		std::cout << "Can't be empty" << std::endl;
		std::getline(std::cin, tmp, '\n');
	}
	phbook->setContactNumber(tmp, phbook->getIndex());

	std::cout << "Darkest secret:" << std::endl;
	std::getline(std::cin, tmp, '\n');
	while (tmp.length() == 0)
	{
		std::cout << "Can't be empty" << std::endl;
		std::getline(std::cin, tmp, '\n');
	}
	phbook->setContactDarkest_secret(tmp, phbook->getIndex());

	phbook->setIndex(phbook->getIndex() + 1);
	if (phbook->getIndex() > 7)
		phbook->setIndex(0);
}

int	main()
{
	PhoneBook	phbook;
	std::string	istream;

	phbook.setIndex(0);
	while (istream != "EXIT")
	{
		std::cout << "ADD for add contact\nSEARCH to access the contact menu\nEXIT to quit" << std::endl;
		std::getline(std::cin, istream, '\n');
		if (std::cin.eof())
			break;
		if (istream == "ADD")
			ft_add(&phbook);
		if (istream == "SEARCH")
			ft_search(&phbook);
	}
}
