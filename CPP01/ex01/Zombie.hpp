#ifndef ZOMBIE_HPP
#  define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:

		std::string	_name;

	public:

		Zombie(std::string ZombieName);
		~Zombie(void);

		void announce( void );

		Zombie( void );
};

Zombie*	zombieHorde( int N, std::string name );

#endif