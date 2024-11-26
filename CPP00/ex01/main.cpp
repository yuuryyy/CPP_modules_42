
#include <iostream>
#include "PhoneBook.hpp"

int	main(int ac, char **av)
{
	std::string	buffer;
	PhoneBook	phonebook;
	int			ContactNum;
	(void)av;

	if (ac != 1)
	{
		std::cerr << RED"Error: No arguments are required." << std::endl;
		return (1);
	}
	ContactNum = -1;
	while (true)
	{
		std::cout << MAGENTA << "------------------------> enter an option : " << RESET ;
		std::getline(std::cin, buffer);
		if (buffer.compare("ADD") == 0)
			phonebook.Add(++ContactNum);
		else if (buffer.compare("SEARCH") == 0)
			phonebook.Search(ContactNum);
		else if (buffer.compare("EXIT") == 0)
			phonebook.Exit();
		else
			phonebook.Other();
	}
	return (0);
}

