#include "Ice.hpp"
#include "ICharacter.hpp"


Ice::Ice( void ) : AMateria("ice") 
{
    // std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice( const Ice &Other ) : AMateria(Other) 
{
    // std::cout << "Ice copy constructor called" << std::endl;
    *this = Other;
}

Ice&
Ice::operator=( const Ice &Other ) 
{
    // std::cout << "Ice assignment operator called" << std::endl;
    if (this != &Other)
    {
        this->_type = Other._type;
    }
    return *this;
}

Ice::~Ice( void ) 
{
    // std::cout << "Ice destructor called" << std::endl;
}

AMateria*
Ice::clone( void ) const 
{
    // std::cout << "Ice clone method called" << std::endl;
    return new Ice(*this);
}

void
Ice::use( ICharacter& target ) 
{
    //     std::cout << "Ice use method called" << std::endl; 
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}