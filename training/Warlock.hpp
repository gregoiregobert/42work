#include <iostream>

class Warlock{

	private :

		Warlock();
		Warlock &operator=( Warlock const &other );
		Warlock( Warlock const &other );
		std::string _name;
		std::string _title;

	public :

		Warlock( std::string name, std::string title);
		~Warlock();

		std::string const	getName() const;
		std::string const	getTitle() const;

		void		setTitle(std::string const title);

		void		introduce() const;
};