
#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		std::string	string;
		for (int i = 1; av[i]; i++)
		{
			string = av[i];
			for (int k = 0; k < string.length(); k++)
			{
				string[k] = toupper(string[k]);
				std::cout << string[k];
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
