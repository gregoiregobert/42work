#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cstddef>

class PMergeMe
{
	private:

		int		_ac;
		char	**_av;

	public:

		PMergeMe( int ac, char **av );
		PMergeMe( const PMergeMe& other );
		~PMergeMe();

		PMergeMe &operator=( const PMergeMe& other);

		void	put_in_array();
		void	check_format();

		class NoArg : public std::exception{
			public:
			virtual const char* what() const throw(){
				return ("\033[1;31mError: Not enough arguments.\033[0m");
			}
		};
};
#endif