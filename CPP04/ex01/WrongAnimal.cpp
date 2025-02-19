#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal( const std::string &type ) : type(type)
{
    std::cout << "WrongAnimal "<< type  << " constructor called." << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &WrongAnimal )
{
    std::cout << "WrongAnimal copy constructor called." << std::endl;
    *this = WrongAnimal;
}

WrongAnimal
&WrongAnimal::operator=( const WrongAnimal &wroong )
{
    std::cout << "WrongAnimal assignation operator called." << std::endl;

    if (this != &wroong)
        this->type = wroong.type;
    return *this;
}

std::string
WrongAnimal::getType( void ) const
{
    return this->type;
}

void
WrongAnimal::makeSound( void ) const
{
    std::cout << "WrongAnimal sound." << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "WrongAnimal " << this->type <<" destructor called." << std::endl;
}
