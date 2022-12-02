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
	std::cout << "First name	: " << phbook->tel[i].first_name << std::endl;
	std::cout << "Last name	: "  << phbook->tel[i].last_name << std::endl;
	std::cout << "Nickname	: "  << phbook->tel[i].nickname << std::endl;
	std::cout << "Number		: "  << phbook->tel[i].number << std::endl;
	std::cout << "Darkest secret	: "  << phbook->tel[i].darkest_secret << std::endl;
}

void	ft_search(PhoneBook *phbook)
{
	int	i;
	int tmp;

	i = -1;
	while (++i < 8)
	{
		std::cout << i
		<< "|" << cut_at_ten(phbook->tel[i].first_name)
		<< "|" << cut_at_ten(phbook->tel[i].last_name)
		<< "|" << cut_at_ten(phbook->tel[i].nickname)
		<< std::endl;
	}
	std::cout << "Hit index of contact you want to see" << std::endl;
	std::cin >> tmp;
	if (tmp > 7 || std::cin.fail() == 1)
		std::cout << "Index does't exist" << std::endl;
	else
		ft_display_contact(tmp, phbook);
	std::cin.clear();
}

void	ft_add(PhoneBook *phbook)
{
	std::string	tmp;

	std::cout << "First name:" << std::endl;
	std::cin >> tmp;
	phbook->tel[phbook->i].first_name = tmp;
	std::cout << "Last name:" << std::endl;
	std::cin >> tmp;
	phbook->tel[phbook->i].last_name = tmp;
	std::cout << "Nickname:" << std::endl;
	std::cin >> tmp;
	phbook->tel[phbook->i].nickname = tmp;
	std::cout << "Number:" << std::endl;
	std::cin >> tmp;
	phbook->tel[phbook->i].number = tmp;
	std::cout << "Darkest secret:" << std::endl;
	std::cin >> tmp;
	phbook->tel[phbook->i].darkest_secret = tmp;
	phbook->i++;
	if (phbook->i > 7)
		phbook->i = 0;
}

int	main()
{
	PhoneBook	phbook;
	std::string	istream;

	phbook.i = 0;
	while (istream != "EXIT")
	{
		std::cin.clear();
		std::cin >> istream;
		if (istream == "ADD")
			ft_add(&phbook);
		if (istream == "SEARCH")
			ft_search(&phbook);
	}
}
