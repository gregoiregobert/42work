#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <cstdlib>
#include <sys/time.h>


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
		std::list<int>	recursive_sort_list(std::list<int> array);
		std::list<int>	insert_list(std::list<int> left, std::list<int> right);

		void				put_in_vector();
		std::vector<int>	recursive_sort_vector(std::vector<int> array);
		std::vector<int>	insert_vector(std::vector<int> left, std::vector<int> right);

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

		class TooManyArg : public std::exception{
			public:
			virtual const char* what() const throw(){
				return ("\033[1;31mError: Too Many arguments.\033[0m");
			}
		};

		class Duplicates : public std::exception{
			public:
			virtual const char* what() const throw(){
				return ("\033[1;31mError: Duplicates arguments.\033[0m");
			}
		};
};
#endif