#ifndef ZOMBIE_HPP
#  define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:

		std::string	_name;
	public:

		void announce( void );

		Zombie(const std::string& ZombieName);
		~Zombie(void);

};

Zombie* newZombie( std::string name );
void	randomChump( std::string name );


#endif