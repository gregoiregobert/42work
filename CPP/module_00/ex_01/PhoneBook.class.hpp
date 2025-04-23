#ifndef	PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <iostream>
# include <string>
# include <cstdlib>
# include <cctype>

class	Contact
{
	public:

		Contact(void);
		~Contact(void);

		std::string	getFirst_name(void);
		void		setFirst_name(std::string first_n);
		std::string	getLast_name(void);
		void		setLast_name(std::string last_n);
		std::string	getNickname(void);
		void		setNickname(std::string nick_n);
		std::string	getNumber(void);
		void		setNumber(std::string nb);
		std::string	getDarkest_secret(void);
		void		setDarkest_secret(std::string darksec);

	private:

		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_number;
		std::string	_darkest_secret;
};

class	PhoneBook
{
	public:

		PhoneBook(void);
		~PhoneBook(void);

		std::string	getContactFirst_name(int index);
		void		setContactFirst_name(std::string first_n, int index);
		std::string	getContactLast_name(int index);
		void		setContactLast_name(std::string last_n, int index);
		std::string	getContactNickname(int index);
		void		setContactNickname(std::string nick_n, int index);
		std::string	getContactNumber(int index);
		void		setContactNumber(std::string nb, int index);
		std::string	getContactDarkest_secret(int index);
		void		setContactDarkest_secret(std::string darksec, int index);

		int			getIndex(void);
		void		setIndex(int i);

	private:

		Contact	tel[8];
		int i;
};

#endif