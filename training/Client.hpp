#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

class Client
{
	private:

		std::string _name;
		std::string	_value;

	public:

		Client(std::string name, std::string value);
};

#endif