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

/////////////// Contact accessors ///////////////

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

/////////////// PhoneBook accessors ///////////////

std::string	PhoneBook::getContactFirst_name(int index)
{
	return (this->tel[index].getFirst_name());
}

void	PhoneBook::setContactFirst_name(std::string first_n, int index)
{
	this->tel[index].setFirst_name(first_n);
}

std::string	PhoneBook::getContactLast_name(int index)
{
	return (this->tel[index].getLast_name());
}

void	PhoneBook::setContactLast_name(std::string first_n, int index)
{
	this->tel[index].setLast_name(first_n);
}

std::string	PhoneBook::getContactNickname(int index)
{
	return (this->tel[index].getNickname());
}

void	PhoneBook::setContactNickname(std::string first_n, int index)
{
	this->tel[index].setNickname(first_n);
}

std::string	PhoneBook::getContactNumber(int index)
{
	return (this->tel[index].getNumber());
}

void	PhoneBook::setContactNumber(std::string first_n, int index)
{
	this->tel[index].setNumber(first_n);
}


std::string	PhoneBook::getContactDarkest_secret(int index)
{
	return (this->tel[index].getDarkest_secret());
}

void	PhoneBook::setContactDarkest_secret(std::string first_n, int index)
{
	this->tel[index].setDarkest_secret(first_n);
}

int	PhoneBook::getIndex(void)
{
	return (this->i);
}

void	PhoneBook::setIndex(int i)
{
	
	this->i = i;
}