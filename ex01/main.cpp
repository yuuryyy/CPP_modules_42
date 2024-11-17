
#include <iostream>

int	main(int ac, char **av)
{
	std::string	buffer;

	if (ac != 1)
	{
		std::cerr << "Error: No arguments are required." << std::endl;
		return (1);
	}
	while (true)
	{
		std::cout << "enter an option : ";
		std::getline(std::cin, buffer);
		
	}
}

