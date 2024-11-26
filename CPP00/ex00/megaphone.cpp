
#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; av[i]; i++)
		{
			for (int k = 0; av[i][k]; k++)
			{
				if (av[i][k] <= 'z' && av[i][k] >= 'a')
					av[i][k] -= 32;
				std::cout << av[i][k];
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
