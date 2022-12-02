#include <iostream>

std::string	upper_case(char *str)
{
	int			i;

	i = -1;
	while (str[++i])
		str[i] = toupper(str[i]);
	return (str);
}
