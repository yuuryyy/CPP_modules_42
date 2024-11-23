#include "Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	Zombie*	ptr = new Zombie( name );

	if (ptr == NULL)
		return (NULL);
	return ptr;
}