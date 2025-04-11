#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : type("AAnimal")
{
    std::cout << "AAnimal default constructor called." << std::endl;
}

AAnimal::AAnimal( const std::string &type ) : type(type)
{
    std::cout << "AAnimal "<< type  << " constructor called." << std::endl;
}

AAnimal::AAnimal( const AAnimal &animal )
{
    std::cout << "AAnimal copy constructor called." << std::endl;
    *this = animal;
}

AAnimal
&AAnimal::operator=( const AAnimal &animal )
{
    std::cout << "AAnimal assignation operator called." << std::endl;

    if (this != &animal)
        this->type = animal.type;
    return *this;
}

std::string
AAnimal::getType( void ) const
{
    return this->type;
}

void
AAnimal::makeSound( void ) const
{
    std::cout << "AAnimal sound." << std::endl;
}

AAnimal::~AAnimal( void )
{
    std::cout << "AAnimal " << this->type <<  " destuctor called." << std::endl;
}
