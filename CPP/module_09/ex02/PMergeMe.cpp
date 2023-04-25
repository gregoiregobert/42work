#include "PMergeMe.hpp"

//****************************************************//
//               Constructor/Destructor               //
//                      Coplien                       //
//****************************************************//

PMergeMe::PMergeMe( int ac, char **av ) : _ac(ac) ,_av(av)
{
	// std::cout << "PMergeMe constructor called" << std::endl;
	if (ac < 3)
		throw PMergeMe::NoArg();
	put_in_list();
}

PMergeMe::PMergeMe( const PMergeMe& other )
{
	*this = other;
}

PMergeMe::~PMergeMe()
{
	// std::cout << "PMergeMe destructor called" << std::endl;
}

PMergeMe	&PMergeMe::operator=( const PMergeMe &other )
{
	// std::cout << "PMergeMe copy constructor called" << std::endl;
	(void)other;
	return (*this);
}

//****************************************************//
//                    Accessor(s)                     //
//****************************************************//


//****************************************************//
//                    Function(s)                     //
//****************************************************//

void	PMergeMe::put_in_list()
{
	std::list<int> list;

	for (int i = 1; i < _ac; i++)
	{
		if (std::atoi(_av[i]) < 1)
			throw BadInput();
		list.push_back(std::atoi(_av[i]));
	}

	std::cout << "Before : ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout <<*it << " ";
	std::cout << std::endl;

	list = recursive_sort(list);

	std::cout << "After : ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout <<*it << " ";
	std::cout << std::endl;
}

std::list<int>	PMergeMe::recursive_sort(std::list<int> array)
{
	if (array.size() > 2)
	{
		std::list<int> left;
		std::list<int> right;
		int i = 0;

		for (std::list<int>::iterator it = array.begin(); it != array.end(); it++)
		{
			if (i < (int)array.size() / 2)
				left.push_back(*it);
			else
				right.push_back(*it);
			i++;
		}
		return ( insert( recursive_sort( left ), recursive_sort( right ) ) );
	}
	else
	{
		if (array.size() > 1)
			if (array.front() > array.back())
				array.reverse();
		return (array);
	}
}

std::list<int>	PMergeMe::insert(std::list<int> left, std::list<int> right)
{
	std::list<int> ret;
	
	while (left.size() && right.size())
	{
		if (left.front() < right.front())
		{
			ret.push_back(left.front());
			left.pop_front();
		}
		else
		{
			ret.push_back(right.front());
			right.pop_front();
		}
	}

	if (left.size() && !right.size())
	{
		while (left.size())
		{
			ret.push_back(left.front());
			left.pop_front();
		}
	}
	if (!left.size() && right.size())
	{
		while (right.size())
		{
			ret.push_back(right.front());
			right.pop_front();
		}
	}
	return (ret);
}