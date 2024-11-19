
#include <iostream>
#include "PhoneBook.hpp"

int	main(int ac, char **av)
{
	std::string	buffer;
	PhoneBook	phonebook;
	(void)av;

	if (ac != 1)
	{
		std::cerr << RED"Error: No arguments are required." << std::endl;
		return (1);
	}
	while (true)
	{
		std::cout << MAGENTA << "------------------------> enter an option : " << RESET ;
		std::getline(std::cin, buffer);
		if (buffer.compare("ADD") == 0)
			phonebook.Add(0);
		exit(0);
	}
}

