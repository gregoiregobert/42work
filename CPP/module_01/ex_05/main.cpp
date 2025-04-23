#include "Harl.hpp"

int	main()
{
	Harl harl;
	std::string buff;
	std::cout << "Your order is ready! (Your reaction must be DEBUG, INFO, WARNING or ERROR)" << std::endl;
	std::getline(std::cin, buff, '\n');
	harl.complain(buff);
	return (0);
}
