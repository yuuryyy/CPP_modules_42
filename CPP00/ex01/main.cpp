
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

		if (std::cin.eof() || std::cin.fail())
			return phonebook.Exit();

		if (buffer == "ADD")
		{
			if (phonebook.Add(++ContactNum) == false)
				return phonebook.Exit();
		}

		else if (buffer == "SEARCH")
		{
			if (phonebook.Search(ContactNum) == false)
				return phonebook.Exit();
		}

		else if (buffer == "EXIT")
			return phonebook.Exit();

		else
			phonebook.Other();
	}
	return (0);
}

