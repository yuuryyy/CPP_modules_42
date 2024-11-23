#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return nullptr;
	Zombie	*Horde = new Zombie[N];

	if (!Horde)
		return nullptr;
	for (int i = 0; i < N ; i++)
		new(&Horde[i])Zombie( name );
	return Horde;
}