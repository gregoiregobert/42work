#include "PhoneBook.class.hpp"

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
	std::cout << "First name	: " << phbook->tel[i].getFirst_name() << std::endl;
	std::cout << "Last name	: "  << phbook->tel[i].getLast_name() << std::endl;
	std::cout << "Nickname	: "  << phbook->tel[i].getNickname() << std::endl;
	std::cout << "Number		: "  << phbook->tel[i].getNumber() << std::endl;
	std::cout << "Darkest secret	: "  << phbook->tel[i].getDarkest_secret() << std::endl;
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
		<< "|" << cut_at_ten(phbook->tel[i].getFirst_name())
		<< "|" << cut_at_ten(phbook->tel[i].getLast_name())
		<< "|" << cut_at_ten(phbook->tel[i].getNickname())
		<< std::endl;
	}
	std::cout << "Type index of contact you want to see" << std::endl;
	std::getline(std::cin, tmp, '\n');
	index = atoi(tmp.c_str());
	if (index > 7 || index < 0)
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
		std::getline(std::cin, tmp, '\n');
	phbook->setContactFirst_name(tmp, phbook->getIndex);

	std::cout << "Last name:" << std::endl;
	std::getline(std::cin, tmp, '\n');
	while (tmp.length() == 0)
		std::getline(std::cin, tmp, '\n');
	phbook->tel[phbook->i].setLast_name(tmp);

	std::cout << "Nickname:" << std::endl;
	std::getline(std::cin, tmp, '\n');
	while (tmp.length() == 0)
		std::getline(std::cin, tmp, '\n');
	phbook->tel[phbook->i].setNickname(tmp);

	std::cout << "Number:" << std::endl;
	std::getline(std::cin, tmp, '\n');
	while (tmp.length() == 0)
		std::getline(std::cin, tmp, '\n');
	phbook->tel[phbook->i].setNumber(tmp);

	std::cout << "Darkest secret:" << std::endl;
	std::getline(std::cin, tmp, '\n');
	while (tmp.length() == 0)
		std::getline(std::cin, tmp, '\n');
	phbook->tel[phbook->i].setDarkest_secret(tmp);

	phbook->i++;
	if (phbook->i > 7)
		phbook->i = 0;
}

int	main()
{
	PhoneBook	phbook;
	std::string	istream;

	phbook.setIndex(0);
	while (istream != "EXIT")
	{
		std::getline(std::cin, istream, '\n');
		if (std::cin.eof())
			break;
		if (istream == "ADD")
			ft_add(&phbook);
		if (istream == "SEARCH")
			ft_search(&phbook);
	}
}
