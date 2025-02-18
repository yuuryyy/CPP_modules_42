#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
    std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog( const Dog &dog ) : Animal("Dog")
{
    std::cout << "Dog copy constructor called." << std::endl;
    *this = dog;
}

Dog
&Dog::operator=( const Dog &dog )
{
    std::cout << "Dog assignation operator called." << std::endl;

    if (this != &dog)
        this->type = dog.type;

    return *this;
}

void
Dog::makeSound( void ) const
{
    std::cout << "WOUF WOUF." << std::endl;
}

Dog::~Dog( void )
{
    std::cout << "Dog destructor called." << std::endl;
}
