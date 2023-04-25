#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdlib>

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

		void			put_in_list();
		std::list<int>	recursive_sort(std::list<int> array);
		std::list<int>	insert(std::list<int> left, std::list<int> right);

		class NoArg : public std::exception{
			public:
			virtual const char* what() const throw(){
				return ("\033[1;31mError: Not enough arguments.\033[0m");
			}
		};

		class BadInput : public std::exception{
			public:
			virtual const char* what() const throw(){
				return ("\033[1;31mError: Bad Input.\033[0m");
			}
		};
};
#endif