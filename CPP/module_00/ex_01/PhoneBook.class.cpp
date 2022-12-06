#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	// std::cout << "Constructor PhoneBook called" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "Destructor PhoneBook called" << std::endl;
	return;
}

Contact::Contact(void)
{
	// std::cout << "Constructor Contact called" << std::endl;
	return;
}

Contact::~Contact(void)
{
	// std::cout << "Destructor Contact called" << std::endl;
	return;
}

std::string	Contact::getFirst_name(void)
{
	return (this->_first_name);
}

void	Contact::setFirst_name(std::string first_n)
{
	this->_first_name = first_n;
}

std::string	Contact::getLast_name(void)
{
	return (this->_last_name);
}

void	Contact::setLast_name(std::string last_n)
{
	this->_last_name = last_n;
}

std::string	Contact::getNickname(void)
{
	return (this->_nickname);
}

void	Contact::setNickname(std::string nick_n)
{
	this->_nickname = nick_n;
}

std::string	Contact::getNumber(void)
{
	return (this->_number);
}

void	Contact::setNumber(std::string nb)
{
	this->_number = nb;
}

std::string	Contact::getDarkest_secret(void)
{
	return (this->_darkest_secret);
}

void	Contact::setDarkest_secret(std::string darksec)
{
	this->_darkest_secret = darksec;
}