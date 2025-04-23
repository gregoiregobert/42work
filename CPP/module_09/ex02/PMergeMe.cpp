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
	put_in_vector();
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
	_ac = other._ac;
	_av = other._av;
	return (*this);
}

//****************************************************//
//                       List                         //
//****************************************************//

void	PMergeMe::put_in_list()
{
	std::list<int> list;
	struct timeval tv;

// TIMER START
	gettimeofday(&tv, NULL);
	double start = 10e5 * tv.tv_sec + tv.tv_usec;

// PUSH
	for (int i = 1; i < _ac; i++)
	{
		if (std::atoi(_av[i]) < 1)
			throw BadInput();
		list.push_back(std::atoi(_av[i]));
	}

// SIZE ERROR
	if (list.size() > 3000)
		throw TooManyArg();

// DUPLICATES ERROR
	int size = list.size();
	list.unique();
	if ( size > (int)list.size() )
		throw Duplicates();

// TEXT
	std::cout << "Before : ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout <<*it << " ";
	std::cout << std::endl;

// ALGO
	list = recursive_sort_list(list);

// TIMER STOP
	gettimeofday(&tv, NULL);
	double end = 10e5 * tv.tv_sec + tv.tv_usec;

// TEXT
	std::cout << "After : ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout <<*it << " ";
	std::cout << std::endl;

	std::cout <<  "Time to process a range of " << list.size() << " elements with std::list : "
			<< end - start << " us" << std::endl;
}

std::list<int>	PMergeMe::recursive_sort_list(std::list<int> array)
{
// DIVIDED ARRAY
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
		return ( insert_list( recursive_sort_list( left ), recursive_sort_list( right ) ) );
	}

// SORT SMALLEST ARRAY
	else
	{
		if (array.size() > 1)
			if (array.front() > array.back())
				array.reverse();
		return (array);
	}
}

std::list<int>	PMergeMe::insert_list(std::list<int> left, std::list<int> right)
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

//****************************************************//
//                     Vector                         //
//****************************************************//

void	PMergeMe::put_in_vector()
{
	std::vector<int> vector;
	struct timeval tv;

// TIMER START
	gettimeofday(&tv, NULL);
	double start = 10e5 * tv.tv_sec + tv.tv_usec;

// PUSH
	for (int i = 1; i < _ac; i++)
	{
		if (std::atoi(_av[i]) < 1)
			throw BadInput();
		vector.push_back(std::atoi(_av[i]));
	}

// TEXT
	// std::cout << "Before : ";
	// for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	// 	std::cout <<*it << " ";
	// std::cout << std::endl;

// ALGO
	vector = recursive_sort_vector(vector);

// TIMER STOP
	gettimeofday(&tv, NULL);
	double end = 10e5 * tv.tv_sec + tv.tv_usec;

// TEXT
	// std::cout << "After : ";
	// for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	// 	std::cout <<*it << " ";
	// std::cout << std::endl;

	std::cout <<  "Time to process a range of " << vector.size() << " elements with std::vector : "
			<< end - start << " us" << std::endl;
}

std::vector<int>	PMergeMe::recursive_sort_vector(std::vector<int> array)
{
	if (array.size() > 2)
	{
		std::vector<int> left;
		std::vector<int> right;
		int i = 0;

		for (std::vector<int>::iterator it = array.begin(); it != array.end(); it++)
		{
			if (i < (int)array.size() / 2)
				left.push_back(*it);
			else
				right.push_back(*it);
			i++;
		}
		return ( insert_vector( recursive_sort_vector( left ), recursive_sort_vector( right ) ) );
	}
	else
	{
		if (array.size() > 1)
		{
			if (array.front() > array.back())
			{
				array.push_back( array.front() );
				array.erase( array.begin() );
			}
		}
		return (array);
	}
}

std::vector<int>	PMergeMe::insert_vector(std::vector<int> left, std::vector<int> right)
{
	std::vector<int> ret;
	
	while (left.size() && right.size())
	{
		if (left.front() < right.front())
		{
			ret.push_back(left.front());
			left.erase( left.begin() );
		}
		else
		{
			ret.push_back(right.front());
			right.erase( right.begin() );
		}
	}

	if (left.size() && !right.size())
	{
		while (left.size())
		{
			ret.push_back(left.front());
			left.erase( left.begin() );
		}
	}
	if (!left.size() && right.size())
	{
		while (right.size())
		{
			ret.push_back(right.front());
			right.erase( right.begin() );
		}
	}
	return (ret);
}
