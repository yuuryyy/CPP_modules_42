#include "Zombie.hpp"

int main()
{
	Zombie	*horde;

	horde = zombieHorde(5, "Boooo");
	if (horde)
	{
		for(int i = 0; i < 5; i++)
			horde[i].announce(); 
		delete[] horde;
	}
	else
		std::cerr << "Error:\n\t\033[91mAllocation for Zombie horde has failed \033[0m" << std::endl;
	while(1);
	return EXIT_SUCCESS;
}