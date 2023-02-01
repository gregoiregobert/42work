#include <iostream>
#include <fstream>
#include <string>


char	*add_name(const char *str)
{
	std::string s;
	char *ret;

	s = str;
	s.append(".replace");
	ret = new char[s.length() + 1];
	for (unsigned long i = 0; i < s.length(); i++)
		ret[i] = s[i];
	ret[s.length()] = 0;
	return (ret);
}

std::string	find_replace(char *s_find, char *s_replace, std::string line)
{
	std::size_t	found;
	std::size_t	tmp_found;
	std::string	find;
	std::string	replace;


	replace = s_replace;
	find = s_find;
	found = line.find(s_find);
	while (found != std::string::npos)
	{
		line.erase(found, find.length());
		line.insert(found, replace);
		tmp_found = found + replace.length();
		found = line.find(s_find, tmp_found);
	}
	return (line);
}

int	main(int ac, char **av)
{
	char		*new_file;
	std::string	line;
	std::string new_line;

	if (ac != 4)
	{
		std::cout << "wrong number of args" << std::endl;
		return (0);
	}
	new_file = add_name(av[1]);
	std::ifstream ifs(av[1]);
	if (ifs.fail())
	{
		std::cout << "file doesn't exist." << std::endl;
		return (0);
	}
	std::ofstream ofs(new_file);
	std::getline(ifs, line);
	while (!ifs.fail())
	{
		new_line = find_replace(av[2], av[3], line);
		ofs << new_line << '\n';
		std::getline(ifs, line);
	}
	delete new_file;
	ifs.close();
}
