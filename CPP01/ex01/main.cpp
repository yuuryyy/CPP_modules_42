#include "Zombie.hpp"

int main()
{
	Zombie	*horde;

	horde = zombieHorde(50, "Boooo");
	for(int i = 0; i < 50; i++)
		horde[i].announce(); 
	delete[] horde;
	return EXIT_SUCCESS;
}