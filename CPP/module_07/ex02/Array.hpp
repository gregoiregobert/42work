#ifndef ARRAY_HPP
# define ARRAY_HPP

template<class T>
class Array
{
	public:

		Array();
		Array(unsigned int n);
		Array(const Array& other);
		~Array();

		&operator=(const Array& other);

		int	size();

		class WrongIndex : public std::exception
		{
			public:
			virtual const char* what() const throw()
			{
				return ("\033[1;31m...........\033[0m");
			}
		};
};

#endif