#include "AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal( void ) : type("AbstractAnimal")
{
    std::cout << "AbstractAnimal default constructor called." << std::endl;
}

AbstractAnimal::AbstractAnimal( const std::string &type ) : type(type)
{
    std::cout << "AbstractAnimal "<< type  << " constructor called." << std::endl;
}

AbstractAnimal::AbstractAnimal( const AbstractAnimal &animal )
{
    std::cout << "AbstractAnimal copy constructor called." << std::endl;
    *this = animal;
}

AbstractAnimal
&AbstractAnimal::operator=( const AbstractAnimal &animal )
{
    std::cout << "AbstractAnimal assignation operator called." << std::endl;

    if (this != &animal)
        this->type = animal.type;
    return *this;
}

std::string
AbstractAnimal::getType( void ) const
{
    return this->type;
}

void
AbstractAnimal::makeSound( void ) const
{
    std::cout << "AbstractAnimal sound." << std::endl;
}

AbstractAnimal::~AbstractAnimal( void )
{
    std::cout << "AbstractAnimal " << this->type <<  " destuctor called." << std::endl;
}
