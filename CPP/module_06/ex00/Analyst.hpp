#ifndef ANALYST_H
# define ANALYST_H

#include <stdexcept>
#include <iostream>


class Analyst
{
	private:

		std::
	
	public:


	class EnoughArg : public std::exception
	{
		public:

		virtual const char* what() const throw()
		{
			return ("\033[1;31mError : no value has been set\033[0m");
		}
	};
};


#endif