#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
    std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat( const Cat &cat ) : Animal("Cat")
{
    std::cout << "Cat copy constructor called." << std::endl;
    *this = cat;
}

Cat
&Cat::operator=( const Cat &cat )
{
    std::cout << "Cat assignation operator called." << std::endl;

    if (this != &cat)
        this->type = cat.type;

    return *this;
}

void
Cat::makeSound( void ) const
{
    std::cout << "WII WII WII." << std::endl;
}

Cat::~Cat( void )
{
    std::cout << "Cat destructor called." << std::endl;
}
