# include "Harl.hpp"

Harl::Harl( void )
{

}

Harl::~Harl( void )
{

}

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout << "I really do!";
	std::cout << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << " You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << "I\'ve been coming for years whereas you started working here since last month.";
	std::cout << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

void	Harl::complain( std::string level )
{
	void (Harl::*funptr)(void) = NULL;

	if (level == "DEBUG")
		funptr = &Harl::debug;
	else if (level == "INFO")  
		funptr = &Harl::info;
	else if (level == "WARNING")
		funptr = &Harl::warning;
	else if (level == "ERROR")
		funptr = &Harl::error;
	else
	{
		std::cerr << "UNKOWN LEVEL !." << std::endl;
		return ;
	}
	(this->*funptr)();
}