#ifndef	PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <iostream>
# include <string>

class	Contact
{
	public:
		Contact(void);
		~Contact(void);

		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	number;
		std::string	darkest_secret;
};

class	PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		Contact	tel[8];
		int i;
};

#endif