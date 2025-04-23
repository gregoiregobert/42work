#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>

class Brain
{
	private:

		std::string ideas[100];

	public:

		Brain();
		Brain( const Brain& other );
		~Brain();

		Brain &operator=( const Brain& other );

		void		setIdea( std::string idea , int i);
		std::string	getIdea( int i );
};

#endif