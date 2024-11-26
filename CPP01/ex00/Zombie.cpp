#include "Zombie.hpp"

Zombie::Zombie(std::string ZombieName)
{
	_name = ZombieName;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " Died from craving braiiiiiiinzzzZ";
	std::cout <<std::endl;
	_name = "";
}

void	Zombie::announce( void )
{
	std::cout << _name << " : ";
	std::cout << "BraiiiiiiinnnzzzZ..";
	std::cout << std::endl;
}

Zombie::Zombie( void )
{}