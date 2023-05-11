#ifndef CHANNEL_HPP
# define CHANNEL_HPP

#include <string>
#include <iostream>
#include <sstream>
#include "Client.hpp"

class Channel
{
	private:

		Client *_listofclient;

	public:

		void screen_value(std::string);
};

#endif