#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat( const WrongCat &WrongCat ) : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat copy constructor called." << std::endl;
    *this = WrongCat;
}

WrongCat
&WrongCat::operator=( const WrongCat &WrongCat )
{
    std::cout << "WrongCat assignation operator called." << std::endl;

    if (this != &WrongCat)
        this->type = WrongCat.type;

    return *this;
}

void
WrongCat::makeSound( void ) const
{
    std::cout << "WII WII WII." << std::endl;
}

WrongCat::~WrongCat( void )
{
    std::cout << "WrongCat destructor called." << std::endl;
}
