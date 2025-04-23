#ifndef UTILS_HPP
# define UTILS_HPP

#include <string>
#include <cctype>
#include <sstream>
#include <iostream>
#include <limits>

bool	str_isdigit( std::string str );
bool	is_integer( std::string str );
bool	is_dot( std::string str );
bool	is_f( std::string str );
bool 	int_overflow( std::string input );
bool 	float_overflow( std::string input );
bool	double_overflow( std::string input );

#endif