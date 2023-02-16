#ifndef ANALYST_H
# define ANALYST_H

#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <sstream>

class Analyst
{
	private:

		std::string	_input;
		Analyst();
	
	public:

		Analyst( std::string input );
		Analyst ( const Analyst& other );
		~Analyst();

		Analyst &operator=( const Analyst& other );

		void	detect_type();
		void	check_input() const;
		bool	str_syntaxe( std::string str ) const;
		void	is_char() const;
		void	is_int() const;
		void	is_double() const;
		void	is_float() const;
		bool	special_character() const;
		void	print_special_double( std::string spe ) const;
		void	print_special_float( std::string spe ) const;
		void	print_int( char c ) const;
		void	print_int( double d ) const;
		void	print_int( float f ) const;
		void	print_float( double d ) const;
		void	print_float( float f) const;
		void	print_double( double d ) const;
		void	print_double( float f ) const;

	/******************************/
	/*         Exceptions         */
	/******************************/

	class EnoughArg : public std::exception
	{
		public:

		virtual const char* what() const throw()
		{
			return ("\033[1;31mError : wrong number of value has been set\033[0m");
		}
	};

	class Not_a_number_Not_a_char : public std::exception
	{
		public:

		virtual const char* what() const throw()
		{
			return ("\033[1;31mError : value you set is not a number or a unique(!) ascii character\033[0m");
		}
	};

	class No_Printable : public std::exception
	{
		public:

		virtual const char* what() const throw()
		{
			return ("\033[1;31mError : value you set is not printable\033[0m");
		}
	};

	class End : public std::exception
	{
		public:

		virtual const char* what() const throw()
		{
			return (0);
		}
	};
};


#endif