#include "Utils.hpp"

bool	str_isdigit( std::string str )
{
	if (!isdigit(str[0]) && str[0] != '-')
		return (0);
	for (int i = 1; i < (int)str.length(); i++)
		if (!isdigit(str[i]))
			return (0);
	return (1);
}

bool	is_integer( std::string str )
{
	int i = 0;

	if (str[i] == '-')
		i++;
	while (i < (int)str.length() && str[i] != '.')
		i++;
	while (i < (int)str.length() && str[i] != 'f')
	{
		if (str[i] > '0')
			return (0);
		i++;
	}
	return (1);
}

bool	is_dot( std::string str )
{
	int found;

	found = str.find('.');
	if ( found != (int)std::string::npos )
		return (1);
	return (0);
}

bool	is_f( std::string str )
{
	int found;

	found = str.find('f');
	if ( found != (int)std::string::npos )
		return (1);
	return (0);
}

bool	int_overflow( std::string input )
{
	double d;
	std::istringstream ss(input);
	ss >> d;

	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		return (1);
	return (0);
}

bool	float_overflow( std::string input )
{
	double d;
	std::istringstream ss(input);
	ss >> d;

	if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
		return (1);
	return (0);
}

bool	double_overflow( std::string input )
{
	long double ld;
	std::istringstream ss(input);
	ss >> ld;

	if (ld > std::numeric_limits<double>::max() || ld < std::numeric_limits<double>::min())
		return (1);
	return (0);
}