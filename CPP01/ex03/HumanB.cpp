#include "HumanB.hpp"


HumanB::HumanB(const std::string &name )
{
	_name = name;
	_weapon = NULL;
}

HumanB::~HumanB( void )
{
	_weapon = NULL;
}

void	HumanB::attack( void )
{
	std::cout << _name;
	if (_weapon)
		std::cout << " attacks with their " <<  _weapon->getType() << std::endl;
	else
		std::cout << " is unarmed" << std::endl;

}


void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}